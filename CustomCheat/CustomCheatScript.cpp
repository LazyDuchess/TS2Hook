#include "pch.h"
#include "CustomCheatScript.h"
#include "SimNameCheat.h"
#include "ResetSimCheat.h"
#include "GetGlobalCheat.h"
#include "SetGlobalCheat.h"
#include "../TS2Hook/Game.h"

ResetSimCheat* gResetSimCheat = new ResetSimCheat();
SimNameCheat* gSimNameCheat = new SimNameCheat();
GetGlobalCheat* gGetGlobalCheat = new GetGlobalCheat();
SetGlobalCheat* gSetGlobalCheat = new SetGlobalCheat();

void CustomCheatScript::OnInit()
{
	TS::cTSCheatSystem* cheatSystem = TS::CheatSystem();
	if (cheatSystem != nullptr)
	{
		cheatSystem->RegisterCheat(gResetSimCheat);
		cheatSystem->RegisterCheat(gSimNameCheat);
		cheatSystem->RegisterCheat(gSetGlobalCheat);
		cheatSystem->RegisterCheat(gGetGlobalCheat);
	}
}