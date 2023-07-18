#include "pch.h"
#include "../TS2Hook/Game.h"
#include "../TS2Hook/Drawing.h"
#include "../TS2Hook/Scenegraph.h"
#include "../TS2Hook/Encoding.h"
#include "TestScript.h"
#include "TestCheat.h"
#include <string>

static TestCheat gTestCheat;

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
    if (pGameStateController != nullptr)
    {
        TS::cTSNeighborhoodInfo* pCurrentNeighborhood = pGameStateController->CurrentNeighborhoodInfo();
        if (pCurrentNeighborhood != nullptr)
        {
            TS::NeighborhoodType currentNeighborhoodType = pCurrentNeighborhood->NeighborhoodType();
            if (currentNeighborhoodType == TS::NeighborhoodType::Downtown)
                SetCASLotName("NLS!");
            else
                SetCASLotName("CAS!");
        }
    }
    if (KeyPressed(VK_NUMPAD2))
    {
        TS::cTSCheatSystem* cheatSystem = TS::CheatSystem();
        if (cheatSystem != nullptr)
        {
            cheatSystem->RegisterCheat(&gTestCheat);
        }
        //TS::cTSGlobals* pGlobals = TS::Globals();
        //TS::cEdithObjectModule* pObjectManager = pGlobals->ObjectManager();
        //pObjectManager->DeleteAllObjects();
    }
    /*
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
        TS::cTSGlobals* pGlobals = TS::Globals();
        TS::cEdithObjectModule* pObjectManager = pGlobals->ObjectManager();
        TS::cTSPerson* pSelectedPerson = pObjectManager->GetSelectedPerson();
        TS::cEdithObject* pSelectedPersonAsObject = pSelectedPerson->AsEdithObject();
        int selectedPersonID = pSelectedPersonAsObject->GetID();
        // Behavior basically defines the scope of where the game will look for the BHAV. So in its private, semiglobal or global.
        TS::cTSBehavior* pBehavior = pSelectedPersonAsObject->GetBehavior();
        char bhavName[] = "DEBUG - Force Twins";
        pSelectedPersonAsObject->RunTree(pBehavior, selectedPersonID, bhavName, 0, 0, 0, 0);
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
    }*/

}

void TestScript::Draw()
{
    TS::cTSGameStateController* pGameStateController = TS::GameStateController();
    std::wstring infoString = L"Debug Data:";
    infoString.append(L"\n");
    if (pGameStateController != nullptr)
    {
        TS::cTSNeighborhoodInfo* nhoodInfo = pGameStateController->CurrentNeighborhoodInfo();
        if (nhoodInfo != nullptr)
        {
            infoString.append(L"Hood Addr: ");
            infoString.append(std::to_wstring((DWORD)nhoodInfo));
            infoString.append(L"\n");
            //infoString.append(L"Hood Type: ");
            //infoString.append(std::to_wstring(nhoodInfo->NeighborhoodType()));
            //infoString.append(L"\n");
        }
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
            infoString.append(L"Lot Name: ");
            infoString.append(lotName->GetWString());
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
                infoString.append(Encoding::UTF8ToWString(std::string(lightState)));
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