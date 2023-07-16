#include "pch.h"
#include "TestScript.h"
#include <string>
#include "../TS2Hook/Game.h"
#include "../TS2Hook/Drawing.h"

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
            char* lotName = lotInfo->LotName();
            infoString.append(L"In a Lot: ");
            infoString.append(std::to_wstring((DWORD)&lotName));
            infoString.append(L"\n");
        }
        else
        {
            infoString.append(L"Not in a Lot");
            infoString.append(L"\n");
        }
    }
    else
    {
        infoString.append(L"GameStateController not instantiated");
    }
    Drawing::DrawTxt(infoString.c_str(), Drawing::Color(255,255,255), 20, 60);
}