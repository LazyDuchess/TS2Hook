#include "pch.h"
#include "../TS2Hook/Game.h"
#include "TestScript.h"

bool KeyPressed(int vKey)
{
    return ((GetAsyncKeyState(vKey) & 0x8001) == 0x8001);
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