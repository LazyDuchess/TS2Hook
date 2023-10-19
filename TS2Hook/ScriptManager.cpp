#include "pch.h"
#include <vector>
#include "ScriptManager.h"
#include "D3DHook.h"
#include <d3d9.h> 
#include <d3dx9.h>
#include <string>
#include "Edith.h"
#include "Drawing.h"
#include "Hooking.h"
#include <chrono>
#pragma comment(lib, "D3D Hook x86.lib")
#pragma comment(lib, "d3dx9.lib")

typedef std::chrono::high_resolution_clock hr_clock;
hr_clock::time_point lastFrameTime;
bool firstFrameTicked = false;
bool drawText = true;

typedef long(__stdcall* tEndScene)(LPDIRECT3DDEVICE9);
typedef long(__stdcall* tReset)(LPDIRECT3DDEVICE9);
tEndScene oD3D9EndScene = NULL;
tReset oD3D9Reset = NULL;
bool bExit = false;
HMODULE gModule;

std::vector<Script*> scripts;

void Draw(LPDIRECT3DDEVICE9 pDevice)
{
    Drawing::OnDraw(pDevice);
    if (drawText)
    {
        std::wstring infoString = L"TS2Hook (";
        infoString.append(std::to_wstring(scripts.size()));
        infoString.append(L" scripts loaded)");
        Drawing::DrawTxt(infoString.c_str(), Drawing::Color(255, 255, 255), 20, 20);
    }
    for (Script* script : scripts)
    {
        script->Draw();
    }
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

// Hooking cTSSimSystem::Init function start (End)
constexpr auto INIT_HOOK_ADDR = 0x007dd1c0;
constexpr auto INIT_HOOK_EXIT_ADDR = INIT_HOOK_ADDR + 6;

// Hooking AppendInteractionsForMenu (End)
constexpr auto APPEND_INTERACTIONS_HOOK_ADDR = 0x008A6803;
constexpr auto APPEND_INTERACTIONS_HOOK_EXIT_ADDR = APPEND_INTERACTIONS_HOOK_ADDR + 8;

// Hooking cTSSimulator::TickAllObjects (Begin)
constexpr auto SIMULATOR_PRESIMULATE_HOOK_ADDR = 0x008719f0;
constexpr auto SIMULATOR_PRESIMULATE_HOOK_EXIT_ADDR = SIMULATOR_PRESIMULATE_HOOK_ADDR + 5;

// Hooking cTSSimulator::InitShared (End)
constexpr auto SIMULATOR_INITSHARED_HOOK_ADDR = 0x008737b4;
constexpr auto SIMULATOR_INITSHARED_HOOK_EXIT_ADDR = SIMULATOR_INITSHARED_HOOK_ADDR + 5;

// Hooking cTSSimulator::Read (End)
constexpr auto SIMULATOR_READ_HOOK_ADDR = 0x00872e73;
constexpr auto SIMULATOR_READ_HOOK_EXIT_ADDR = SIMULATOR_READ_HOOK_ADDR + 5;

// Hooking cTSSimulator::Write (Begin)
constexpr auto SIMULATOR_WRITE_BEGIN_HOOK_ADDR = 0x00872751;
constexpr auto SIMULATOR_WRITE_BEGIN_HOOK_EXIT_ADDR = SIMULATOR_WRITE_BEGIN_HOOK_ADDR + 5;

// Hooking cTSSimulator::Write (End)
constexpr auto SIMULATOR_WRITE_END_HOOK_ADDR = 0x008728da;
constexpr auto SIMULATOR_WRITE_END_HOOK_EXIT_ADDR = SIMULATOR_WRITE_END_HOOK_ADDR + 5;

// Hooking TryGenericSimCall (Begin)
constexpr auto TRYGENERICSIMCALL_HOOK_ADDR = 0x0094c3e0;
constexpr auto TRYGENERICSIMCALL_HOOK_EXIT_ADDR = TRYGENERICSIMCALL_HOOK_ADDR + 5;

// Hooking nTSSG::cTSSGSystem::OncePërFrameUpdate (Begin)
constexpr auto ONCEPERFRAMEUPDATE_HOOK_ADDR = 0x00b271d0;
constexpr auto ONCEPERFRAMEUPDATE_HOOK_EXIT_ADDR = ONCEPERFRAMEUPDATE_HOOK_ADDR + 6;

// Hooking nTSSG::cTSSGSystem::PostLoadLot (End)
constexpr auto POSTLOADLOT_HOOK_ADDR = 0x00B2F007;
constexpr auto POSTLOADLOT_HOOK_EXIT_ADDR = POSTLOADLOT_HOOK_ADDR + 6;

// nTSSG::cTSSGSystem::onNeighborhoodEntered (End)
constexpr auto NEIGHBORHOODENTER_HOOK_ADDR = 0x00B2922D;
constexpr auto NEIGHBORHOODENTER_HOOK_EXIT_ADDR = NEIGHBORHOODENTER_HOOK_ADDR + 6;

// Hooking cTSWinProcMain::FlipToShellMode (End)
constexpr auto FLIPTOSHELL_HOOK_ADDR = 0x0055b848;
constexpr auto FLIPTOSHELL_HOOK_EXIT_ADDR = FLIPTOSHELL_HOOK_ADDR + 5;

void __stdcall On_ShellEntered()
{
    for (Script* script : scripts)
    {
        script->OnShellEntered();
    }
}

void __declspec(naked) cTSWinProcMain_FlipToShellMode_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        call On_ShellEntered

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        pop ebx
        leave
        ret 8
    }
}

void __stdcall On_NeighborhoodEntered()
{
    drawText = false;
    for (Script* script : scripts)
    {
        script->OnNeighborhoodEntered();
    }
}

void __declspec(naked) cTSSGSystem_NeighborhoodEntered_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        call On_NeighborhoodEntered

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        add esp, 0x2C
        ret 8
    }
}

void __stdcall On_PostLoadLot()
{
    drawText = false;
    for (Script* script : scripts)
    {
        script->OnLotLoaded();
    }
}

void __declspec(naked) cTSSGSystem_PostLoadLot_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        call On_PostLoadLot

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        add esp, 0x2C
        ret 4
    }
}

void __stdcall On_OncePerFrameUpdate()
{
    auto thisFrameTime = hr_clock::now();
    if (!firstFrameTicked)
    {
        lastFrameTime = thisFrameTime;
        firstFrameTicked = true;
    }
    float deltaTime = std::chrono::duration<float>(thisFrameTime - lastFrameTime).count();
    lastFrameTime = thisFrameTime;
    for (Script* script : scripts)
    {
        script->Update(deltaTime);
    }
}

void __declspec(naked) cTSSGSystem_OncePerFrameUpdate_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        call On_OncePerFrameUpdate

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        mov eax,fs:[0]
        jmp ONCEPERFRAMEUPDATE_HOOK_EXIT_ADDR
    }
}

EdithReturnValue __stdcall On_TryGenericSimCall(cTSTreeStackElem* stack, XPrimParam* primitive)
{
    char call = primitive->GetChar(0);
    int uid = primitive->GetInt(1);
    if (call == 0x55)
    {
        for (Script* script : scripts)
        {
            if (script->GetID() == uid)
                return EdithReturnValue::True;
        }
        return EdithReturnValue::False;
    }
    else if (call == 0x56)
    {
        for (Script* script : scripts)
        {
            if (script->GetID() == uid)
                return script->OnEdithCall(stack, primitive);
        }
        return EdithReturnValue::Unhandled;
    }
    return EdithReturnValue::Unhandled;
}

void __declspec(naked) On_TryGenericSimCall_Hook()
{
    __asm {
        push edi
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        //args, last pushed first
        //xprimparam
        push[esp + 24+8]
        //ctstreestackelem
        push[esp + 28+4]

        call On_TryGenericSimCall
        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop edi

        // EdithReturnValue::Unhandled
        cmp eax, 0x2
        je OnUnhandled
        ret 0x8
        OnUnhandled:
        // Original
        push ebp
        mov ebp, esp
        push -01

        jmp TRYGENERICSIMCALL_HOOK_EXIT_ADDR
    }
}

void SetTS2HookInstalledGlobal(TS::cTSSimulator* simulator)
{
    simulator->SetGlobal(0x2, 1);
}

void UnsetTS2HookInstalledGlobal(TS::cTSSimulator* simulator)
{
    simulator->SetGlobal(0x2, 0);
}

void __stdcall On_cTSSimulator_InitShared(TS::cTSSimulator* simulator)
{
    SetTS2HookInstalledGlobal(simulator);
    for (Script* script : scripts)
    {
        script->OnSimulatorInit(simulator);
    }
}

void __declspec(naked) cTSSimulator_InitShared_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        // cTSSimulator*
        push esi
        call On_cTSSimulator_InitShared

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        mov ecx, [esp+0x24]
        pop edi
        jmp SIMULATOR_INITSHARED_HOOK_EXIT_ADDR
    }
}

void __stdcall On_cTSSimulator_Read(TS::cTSSimulator* simulator)
{
    SetTS2HookInstalledGlobal(simulator);
    for (Script* script : scripts)
    {
        script->OnSimulatorFinishLoading(simulator);
    }
}

void __declspec(naked) cTSSimulator_Read_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        // cTSSimulator*
        push esi
        call On_cTSSimulator_Read

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        mov edx, [ebp+0x00]
        mov ecx, ebp
        jmp SIMULATOR_READ_HOOK_EXIT_ADDR
    }
}

void __stdcall On_cTSSimulator_Write_Begin(TS::cTSSimulator* simulator)
{
    UnsetTS2HookInstalledGlobal(simulator);
    for (Script* script : scripts)
    {
        script->OnSimulatorSaveBegin(simulator);
    }
}

void __declspec(naked) cTSSimulator_Write_Begin_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        // cTSSimulator*
        push ecx
        call On_cTSSimulator_Write_Begin

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        push 0x53494D49
        jmp SIMULATOR_WRITE_BEGIN_HOOK_EXIT_ADDR
    }
}

void __stdcall On_cTSSimulator_Write_End(TS::cTSSimulator* simulator)
{
    SetTS2HookInstalledGlobal(simulator);
    for (Script* script : scripts)
    {
        script->OnSimulatorSaveEnd(simulator);
    }
}

void __declspec(naked) cTSSimulator_Write_End_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        // cTSSimulator*
        push edi
        call On_cTSSimulator_Write_End

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        neg al
        pop edi
        pop esi
        pop ebp
        jmp SIMULATOR_WRITE_END_HOOK_EXIT_ADDR
    }
}

void __stdcall On_cTSSimulator_PreSimulate(TS::cTSSimulator* simulator)
{
    for (Script* script : scripts)
    {
        script->OnPreSimulate(simulator);
    }
}

void __declspec(naked) cTSSimulator_PreSimulate_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        // cTSSimulator*
        push ecx
        call On_cTSSimulator_PreSimulate

        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        sub esp, 0x08
        push ebx
        push ebp
        jmp SIMULATOR_PRESIMULATE_HOOK_EXIT_ADDR
    }
}

void __stdcall On_cEdithObjectTestSim_AppendInteractionsForMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim)
{
    bool debug = false;
    TS::cTSGlobals* pGlobals = TS::Globals();
    // Flag 0x2000 on an object means we're shift clicking it (debug interactions are shown in testingcheats)
    if (pGlobals->TestingCheatsEnabled() && testSim->object->GetMiscFlag(0x2000))
        debug = true;
    for (Script* script : scripts)
    {
        script->OnBuildUserDirectedInteractionMenu(interactions, testSim, debug);
    }
}

void __declspec(naked) cEdithObjectTestSim_AppendInteractionsForMenu_Hook()
{
    __asm {
        push edi
        push eax
        push edx
        push ecx
        push ebp
        push ebx
        push esi

        //args, last pushed first
        //testSim
        push esi
        //interactions vector
        push ebp

        call On_cEdithObjectTestSim_AppendInteractionsForMenu
        pop esi
        pop ebx
        pop ebp
        pop ecx
        pop edx
        pop eax
        pop edi
        // Original
        pop edi
        pop esi
        pop ebp
        pop ebx
        mov ecx,[esp+0x24]

        jmp APPEND_INTERACTIONS_HOOK_EXIT_ADDR
    }
}

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
        // Original
        mov eax, fs:[00000000]
        jmp INIT_HOOK_EXIT_ADDR
    }
}

void ScriptManager::Initialize(HMODULE hModule)
{
    Hooking::MakeJMP((BYTE*)APPEND_INTERACTIONS_HOOK_ADDR, (DWORD)cEdithObjectTestSim_AppendInteractionsForMenu_Hook, 8);
    Hooking::MakeJMP((BYTE*)INIT_HOOK_ADDR, (DWORD)cTSSimSystem_Init_Hook, 6);
    Hooking::MakeJMP((BYTE*)SIMULATOR_PRESIMULATE_HOOK_ADDR, (DWORD)cTSSimulator_PreSimulate_Hook, 5);
    Hooking::MakeJMP((BYTE*)SIMULATOR_INITSHARED_HOOK_ADDR, (DWORD)cTSSimulator_InitShared_Hook, 5);
    Hooking::MakeJMP((BYTE*)SIMULATOR_READ_HOOK_ADDR, (DWORD)cTSSimulator_Read_Hook, 5);
    Hooking::MakeJMP((BYTE*)SIMULATOR_WRITE_BEGIN_HOOK_ADDR, (DWORD)cTSSimulator_Write_Begin_Hook, 5);
    Hooking::MakeJMP((BYTE*)SIMULATOR_WRITE_END_HOOK_ADDR, (DWORD)cTSSimulator_Write_End_Hook, 5);
    Hooking::MakeJMP((BYTE*)TRYGENERICSIMCALL_HOOK_ADDR, (DWORD)On_TryGenericSimCall_Hook, 5);
    Hooking::MakeJMP((BYTE*)ONCEPERFRAMEUPDATE_HOOK_ADDR, (DWORD)cTSSGSystem_OncePerFrameUpdate_Hook, 6);
    Hooking::MakeJMP((BYTE*)POSTLOADLOT_HOOK_ADDR, (DWORD)cTSSGSystem_PostLoadLot_Hook, 6);
    Hooking::MakeJMP((BYTE*)NEIGHBORHOODENTER_HOOK_ADDR, (DWORD)cTSSGSystem_NeighborhoodEntered_Hook, 6);
    Hooking::MakeJMP((BYTE*)FLIPTOSHELL_HOOK_ADDR, (DWORD)cTSWinProcMain_FlipToShellMode_Hook, 5);
    //Hooking::MakeJMP((BYTE*)SIMULATOR_GETGLOBAL_HOOK_ADDR, (DWORD)cTSSimulator_GetGlobal_Hook, 5);
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

Script* ScriptManager::GetScript(int id)
{
    for (Script* script : scripts)
    {
        if (script->GetID() == id)
            return script;
    }
    return nullptr;
}