// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "CustomCheatScript.h"
#include "../TS2Hook/ScriptManager.h"

static CustomCheatScript gCustomCheatScript;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        ScriptManager::Register(&gCustomCheatScript);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

