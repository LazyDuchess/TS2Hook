#include "pch.h"
#include "CustomCheatScript.h"
#include "SimNameCheat.h"
#include "ResetSimCheat.h"
#include "../TS2Hook/Game.h"

ResetSimCheat* gResetSimCheat = new ResetSimCheat();
SimNameCheat* gSimNameCheat = new SimNameCheat();

void CustomCheatScript::OnInit()
{
	TS::cTSCheatSystem* cheatSystem = TS::CheatSystem();
	if (cheatSystem != nullptr)
	{
		cheatSystem->RegisterCheat(gResetSimCheat);
		cheatSystem->RegisterCheat(gSimNameCheat);
	}
}