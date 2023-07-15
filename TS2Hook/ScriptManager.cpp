#include "pch.h"
#include <vector>
#include "ScriptManager.h"
#include "D3DHook.h"
#include <d3d9.h> 
#include <d3dx9.h>
#include <string>
#pragma comment(lib, "D3D Hook x86.lib")
#pragma comment(lib, "d3dx9.lib")

typedef long(__stdcall* tEndScene)(LPDIRECT3DDEVICE9);
typedef long(__stdcall* tReset)(LPDIRECT3DDEVICE9);
tEndScene oD3D9EndScene = NULL;
tReset oD3D9Reset = NULL;
bool bExit = false;
HMODULE gModule;

std::vector<Script*> scripts;

LPD3DXFONT font = NULL;

void DrawTxt(LPD3DXFONT font, LPCWSTR string, D3DCOLOR fontColor, int left, int top)
{
    RECT rct; //Font
    rct.left = left;
    rct.right = 800;
    rct.top = top;
    rct.bottom = 800;
    font->DrawTextW(NULL, string, -1, &rct, 0, fontColor);
}

void Draw(LPDIRECT3DDEVICE9 pDevice)
{
    if (font == NULL)
    {
        HRESULT res = D3DXCreateFont(pDevice, 17, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &font);
        if (res != S_OK)
            font = NULL;
    }
    else
    {
        std::wstring infoString = L"TS2Hook (";
        infoString.append(std::to_wstring(scripts.size()));
        infoString.append(L" scripts loaded)");
        DrawTxt(font, infoString.c_str(), D3DCOLOR_ARGB(255, 255, 255, 255), 20, 20);
    }
}

long _stdcall hkD3D9Reset(LPDIRECT3DDEVICE9 pDevice)
{
    if (font != NULL)
    {
        font->Release();
        font = NULL;
    }
    return oD3D9Reset(pDevice);
}

long __stdcall hkD3D9EndScene(LPDIRECT3DDEVICE9 pDevice)
{
    for (Script* script : scripts)
    {
        script->Update();
    }
    Draw(pDevice);
    return oD3D9EndScene(pDevice);
}

void ScriptManager::Initialize(HMODULE hModule)
{
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