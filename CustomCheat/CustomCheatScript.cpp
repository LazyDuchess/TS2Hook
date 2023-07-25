#include "pch.h"
#include "CustomCheatScript.h"
#include "SimNameCheat.h"
#include "ResetSimCheat.h"
#include "GetGlobalCheat.h"
#include "SetGlobalCheat.h"
#include "FlipUICheat.h"
#include "MessageBoxCheat.h"
#include "../TS2Hook/Game.h"
#include "../TS2Hook/UI.h"

ResetSimCheat* gResetSimCheat = new ResetSimCheat();
SimNameCheat* gSimNameCheat = new SimNameCheat();
GetGlobalCheat* gGetGlobalCheat = new GetGlobalCheat();
SetGlobalCheat* gSetGlobalCheat = new SetGlobalCheat();
FlipUICheat* gFlipUICheat = new FlipUICheat();
MessageBoxCheat* gMessageBoxCheat = new MessageBoxCheat();

int CustomCheatScript::GetID()
{
	static const int hash = 0x98BEDB51;
	return hash;
}

void CustomCheatScript::OnInit()
{
	TS::cTSCheatSystem* cheatSystem = TS::CheatSystem();
	if (cheatSystem != nullptr)
	{
		cheatSystem->RegisterCheat(gResetSimCheat);
		cheatSystem->RegisterCheat(gSimNameCheat);
		cheatSystem->RegisterCheat(gSetGlobalCheat);
		cheatSystem->RegisterCheat(gGetGlobalCheat);
		cheatSystem->RegisterCheat(gFlipUICheat);
		cheatSystem->RegisterCheat(gMessageBoxCheat);
	}
}