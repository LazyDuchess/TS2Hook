#include "pch.h"
#include "TestScript.h"
#include <string>
#include "../TS2Hook/Game.h"
#include "../TS2Hook/Drawing.h"
#include "../TS2Hook/Scenegraph.h"

bool KeyPressed(int vKey)
{
    return ((GetAsyncKeyState(vKey) & 0x8001) == 0x8001);
}

bool KeyDown(int vKey)
{
    return GetAsyncKeyState(vKey) & 0x8000;
}

void TestScript::Update()
{
    TS::cTSGameStateController* pGameStateController = TS::GameStateController();
    if (KeyPressed(VK_ADD))
    {
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
    if (KeyPressed(VK_NUMPAD1))
    {
        nTSSG::cTSSGSystem* sgSystem = TS::SGSystem();
        if (sgSystem != nullptr)
        {
            nTSSG::cLightingManager* lightingManager = sgSystem->LightingManager();
            if (lightingManager != nullptr)
            {
                char state[] = "CAS";
                lightingManager->SetLightingState(state);
            }
        }
    }
    if (KeyPressed(VK_NUMPAD0))
    {
        nTSSG::cTSSGSystem* sgSystem = TS::SGSystem();
        if (sgSystem != nullptr)
        {
            nTSSG::cLightingManager* lightingManager = sgSystem->LightingManager();
            if (lightingManager != nullptr)
            {
                lightingManager->UpdateLightingState();
                //char state[] = "neighborhoodnight";
                //lightingManager->SetLightingState(state);
            }
        }
    }
    if (KeyPressed(VK_HOME))
    {
        TS::cTSCheatSystem* cheatSystem = TS::CheatSystem();
        if (cheatSystem != nullptr)
        {
            char cheat[] = "terrainType Desert";
            TS::cTSCheatParser* cheatParser = cheatSystem->AsParser();
            cheatParser->ExecuteCommand(cheat);
        }
        /*
        TS::cTSLotInfo* lotInfo = pGameStateController->CurrentLotInfo();
        if (lotInfo != nullptr)
        {
            lotInfo->SetLocation(20, 20);
        }*/
    }
}

void TestScript::Draw()
{
    TS::cTSGameStateController* pGameStateController = TS::GameStateController();
    std::wstring infoString = L"Debug Data:";
    infoString.append(L"\n");
    if (pGameStateController != nullptr)
    {
        if (pGameStateController->InCASLot())
            infoString.append(L"In CAS");
        else
            infoString.append(L"Not in CAS");
        infoString.append(L"\n");
        TS::cTSLotInfo* lotInfo = pGameStateController->CurrentLotInfo();
        if (lotInfo != nullptr)
        {
            int lotID = lotInfo->LotID();
            cTSString* lotName = lotInfo->LotName();
            std::wstring ws(lotName->str, lotName->str + strlen(lotName->str));
            infoString.append(L"Lot Name: ");
            infoString.append(ws);
            infoString.append(L"\n");
            infoString.append(L"Lot ID: ");
            infoString.append(std::to_wstring(lotID));
            infoString.append(L"\n");
            int lotXSize = 0;
            int lotYSize = 0;
            lotInfo->GetCurrentSize(&lotXSize, &lotYSize);
            infoString.append(L"Lot Size:");
            infoString.append(L"\n");
            infoString.append(L"X:");
            infoString.append(std::to_wstring(lotXSize));
            infoString.append(L"\n");
            infoString.append(L"Y:");
            infoString.append(std::to_wstring(lotYSize));
            infoString.append(L"\n");
            infoString.append(L"\n");
        }
        nTSSG::cTSSGSystem* sgSystem = TS::SGSystem();
        if (sgSystem != nullptr)
        {
            nTSSG::cLightingManager* lightingManager = sgSystem->LightingManager();
            if (lightingManager != nullptr)
            {
                infoString.append(L"Lighting State: ");
                char* lightState = lightingManager->LightingState();
                std::wstring ws2(lightState, lightState + strlen(lightState));
                infoString.append(ws2);
                infoString.append(L"\n");
            }
        }
        
        /*
        TS::cTSLotInfo* lotInfo = pGameStateController->CurrentLotInfo();
        if (lotInfo != nullptr)
        {
            int lotId = lotInfo->LotID();
            infoString.append(L"In a Lot: ");
            infoString.append(std::to_wstring(lotId));
            infoString.append(L"\n");
        }
        else
        {
            infoString.append(L"Not in a Lot");
            infoString.append(L"\n");
        }*/
    }
    else
    {
        infoString.append(L"GameStateController not instantiated");
    }
    Drawing::DrawTxt(infoString.c_str(), Drawing::Color(255,255,255), 20, 60);
}