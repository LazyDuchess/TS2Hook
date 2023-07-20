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
namespace TS
{

	cTSSimSystem* SimSystem()
	{
		typedef cTSSimSystem* func(void);
		return ((func*)0x00799a63)();
	}

	cTSGameStateController* GameStateController() {
		typedef cTSGameStateController* func(void);
		return ((func*)0x00799b65)();
	}

	cTSGlobals* Globals() {
		typedef cTSGlobals* func(void);
		return ((func*)0x00799a0d)();
	}

	cTSCheatSystem* CheatSystem() {
		typedef cTSCheatSystem* func(void);
		return ((func*)0x00cd4260)();
	}

	void AddCheatInteraction(std::vector<cTSInteraction*>* interactions, cTSPerson* person, cTSObject* object, InteractionType immediate, int flags, const char* name, int instanceId) {
		typedef void func(std::vector<cTSInteraction*>* interactions, cTSPerson* person, cTSObject* object, InteractionType immediate, int flags, const char* name, int instanceId);
		return ((func*)0x008a4fc0)(interactions, person, object, immediate, flags, name, instanceId);
	}

	cRZLanguageManager* LanguageManager() {
		typedef cRZLanguageManager* func(void);
		return ((func*)0x00799cfa)();
	}
}