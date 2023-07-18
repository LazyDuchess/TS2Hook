#include "pch.h"
#include "Game.h"

#define CAS_LOTNAME_SIZE 5
#define YACAS_LOTNAME_SIZE 7

#define CAS_LOTNAME_ADDR 0x011D91D4
#define YACAS_LOTNAME_ADDR 0x011f3630

int SwapLot(int lotID, int neighborhoodID)
{
	typedef int t_swaplot(int, int);
	return ((t_swaplot*)0x0093c710)(lotID, neighborhoodID);
}

char* GetCASLotName()
{
	char lotName[CAS_LOTNAME_SIZE] = { NULL };
	strcpy_s(lotName, CAS_LOTNAME_SIZE, (const char*)CAS_LOTNAME_ADDR);
	return lotName;
}

char* GetYACASLotName()
{
	char lotName[YACAS_LOTNAME_SIZE] = { NULL };
	strcpy_s(lotName, YACAS_LOTNAME_SIZE, (const char*)CAS_LOTNAME_ADDR);
	return lotName;
}

void SetCASLotName(const char* lotName)
{
	DWORD oldProtect;
	VirtualProtect((LPVOID)(CAS_LOTNAME_ADDR), CAS_LOTNAME_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect);
	strcpy_s((char*)CAS_LOTNAME_ADDR, CAS_LOTNAME_SIZE, lotName);
	VirtualProtect((LPVOID)(CAS_LOTNAME_ADDR), CAS_LOTNAME_SIZE, oldProtect, &oldProtect);
}

void SetYACASLotName(const char* lotName)
{
	DWORD oldProtect;
	VirtualProtect((LPVOID)(YACAS_LOTNAME_ADDR), YACAS_LOTNAME_SIZE, PAGE_EXECUTE_READWRITE, &oldProtect);
	strcpy_s((char*)YACAS_LOTNAME_ADDR, YACAS_LOTNAME_SIZE, lotName);
	VirtualProtect((LPVOID)(YACAS_LOTNAME_ADDR), YACAS_LOTNAME_SIZE, oldProtect, &oldProtect);
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