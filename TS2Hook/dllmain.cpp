// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Game.h"
#include "D3DHook.h"
#include <d3d9.h> 
#include <d3dx9.h>
#pragma comment(lib, "D3D Hook x86.lib")
#pragma comment(lib, "d3dx9.lib")

typedef long(__stdcall* tEndScene)(LPDIRECT3DDEVICE9);
tEndScene oD3D9EndScene = NULL;
bool bExit = false;
HMODULE g_Module;

bool KeyPressed(int vKey)
{
    return ((GetAsyncKeyState(vKey) & 0x8001) == 0x8001);
}

void Update() {
    if (KeyPressed(VK_ADD))
    {
        TS::cTSGameStateController* pGameStateController = TS::GameStateController();
        if (pGameStateController != nullptr)
        {
            bool saveEnabled = pGameStateController->SaveLotEnabled();
            if (saveEnabled)
                MessageBox(NULL, L"Yoo lot can be saved.", L"Yo", MB_OK);
            else
                MessageBox(NULL, L"Can't save lot lol.", L"Yo", MB_OK);
        }
    }
    if (KeyPressed(VK_SUBTRACT))
    {
        // Go to pleasantview
        SwapLot(0, 1);
    }
}

long __stdcall hkD3D9EndScene(LPDIRECT3DDEVICE9 pDevice)
{
    Update();
    return oD3D9EndScene(pDevice);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        g_Module = hModule;
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, [](LPVOID) -> DWORD
            {
                bool d3dInitialized = false;
                while (d3dInitialized == false)
                {
                    d3dInitialized = init_D3D();
                }


                methodesHook(42, hkD3D9EndScene, (LPVOID*)&oD3D9EndScene); // hook endscene

                while (!bExit)
                {
                    Sleep(100); // Sleeps until shutdown
                }

                methodesUnhook(); // disables and removes all hooks

                FreeLibraryAndExitThread(g_Module, 0);
            }, nullptr, 0, nullptr);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

