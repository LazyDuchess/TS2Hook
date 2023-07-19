#include "pch.h"
#include <vector>
#include "ScriptManager.h"
#include "D3DHook.h"
#include <d3d9.h> 
#include <d3dx9.h>
#include <string>
#include "Drawing.h"
#include "Hooking.h"
#pragma comment(lib, "D3D Hook x86.lib")
#pragma comment(lib, "d3dx9.lib")

typedef long(__stdcall* tEndScene)(LPDIRECT3DDEVICE9);
typedef long(__stdcall* tReset)(LPDIRECT3DDEVICE9);
typedef long(__stdcall* tPresent)(LPDIRECT3DDEVICE9);
tEndScene oD3D9EndScene = NULL;
tReset oD3D9Reset = NULL;
tPresent oD3D9Present = NULL;
bool bExit = false;
HMODULE gModule;

std::vector<Script*> scripts;

void Draw(LPDIRECT3DDEVICE9 pDevice)
{
    Drawing::OnDraw(pDevice);
    std::wstring infoString = L"TS2Hook (";
    infoString.append(std::to_wstring(scripts.size()));
    infoString.append(L" scripts loaded)");
    Drawing::DrawTxt(infoString.c_str(), Drawing::Color(255,255,255), 20, 20);
    for (Script* script : scripts)
    {
        script->Draw();
    }
}

long _stdcall hkD3D9Present(LPDIRECT3DDEVICE9 pDevice)
{
    for (Script* script : scripts)
    {
        script->Update();
    }
    return oD3D9Present(pDevice);
}

long _stdcall hkD3D9Reset(LPDIRECT3DDEVICE9 pDevice)
{
    Drawing::OnReset(pDevice);
    return oD3D9Reset(pDevice);
}

IDirect3DSurface9* backBuffer;
IDirect3DSurface9* renderTarget;

long __stdcall hkD3D9EndScene(LPDIRECT3DDEVICE9 pDevice)
{
    // Obtain the render target..
    
    if (SUCCEEDED(pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer)) &&
        SUCCEEDED(pDevice->GetRenderTarget(0, &renderTarget)))
    {
        if (backBuffer == renderTarget)
        {
            Draw(pDevice);
        }
    }

    // Cleanup the objects..
    backBuffer->Release();
    renderTarget->Release();
    
    return oD3D9EndScene(pDevice);
}

// Hooking cTSSimSystem::Init function start
constexpr auto INIT_HOOK_ADDR = 0x007dd1c0;
constexpr auto INIT_HOOK_EXIT_ADDR = INIT_HOOK_ADDR + 6;

void __stdcall On_cTSSimSystem_Init()
{
    for (Script* script : scripts)
    {
        script->OnInit();
    }
}

void __declspec(naked) cTSSimSystem_Init_Hook()
{
    __asm {
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi
        call On_cTSSimSystem_Init
        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax

        mov eax, fs:[00000000]
        jmp INIT_HOOK_EXIT_ADDR
    }
}

void ScriptManager::Initialize(HMODULE hModule)
{
    Hooking::MakeJMP((BYTE*)INIT_HOOK_ADDR, (DWORD)cTSSimSystem_Init_Hook, 6);
	gModule = hModule;
    CreateThread(nullptr, 0, [](LPVOID) -> DWORD
    {
        bool d3dInitialized = false;
        while (d3dInitialized == false)
        {
            d3dInitialized = init_D3D();
        }
        
        methodesHook(42, hkD3D9EndScene, (LPVOID*)&oD3D9EndScene); // hook endscene
        methodesHook(16, hkD3D9Reset, (LPVOID*)&oD3D9Reset);
        methodesHook(17, hkD3D9Present, (LPVOID*)&oD3D9Present);

        while (!bExit)
        {
            Sleep(250);
        }
        methodesUnhook(); // disables and removes all hooks
        FreeLibraryAndExitThread(gModule, 0);
    }, nullptr, 0, nullptr);
}

void ScriptManager::Register(Script* script)
{
	scripts.push_back(script);
}