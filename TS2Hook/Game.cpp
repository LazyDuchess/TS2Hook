#include "pch.h"
#include "Game.h"

int SwapLot(int lotID, int neighborhoodID)
{
	typedef int t_swaplot(int, int);
	return ((t_swaplot*)0x0093c710)(lotID, neighborhoodID);
}

TS::cTSSimSystem* TS::SimSystem()
{
	typedef cTSSimSystem* func(void);
	return ((func*)0x00799a63)();
}

TS::cTSGameStateController* TS::GameStateController() {
	typedef cTSGameStateController* func(void);
	return ((func*)0x00799b65)();
}

TS::cTSGlobals* TS::Globals() {
	typedef cTSGlobals* func(void);
	return ((func*)0x00799a0d)();
}

TS::cTSCheatSystem* TS::CheatSystem() {
	typedef cTSCheatSystem* func(void);
	return ((func*)0x00cd4260)();
}