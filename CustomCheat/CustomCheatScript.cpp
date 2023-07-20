#include "pch.h"
#include "CustomCheatScript.h"
#include "ResetSimsCheat.h"
#include "../TS2Hook/Game.h"

ResetSimsCheat* gResetSimsCheat = new ResetSimsCheat();

void CustomCheatScript::OnInit()
{
	TS::cTSCheatSystem* cheatSystem = TS::CheatSystem();
	if (cheatSystem != nullptr)
	{
		cheatSystem->RegisterCheat(gResetSimsCheat);
	}
}