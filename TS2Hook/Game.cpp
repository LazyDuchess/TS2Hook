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
	void cTSGameStateController::FlipUI(int ui, int unk, int unk2) {
		typedef void __stdcall func(int ui, int unk, int unk2);
		((func*)0x00eea5f1)(ui, unk, unk2);
	}

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

	/// <summary>
	/// Adds an interaction to an interaction vector.
	/// </summary>
	/// <param name="interactions">Interaction vector</param>
	/// <param name="person">Person</param>
	/// <param name="object">Target object</param>
	/// <param name="immediate">Whether the interaction should run immediately or blocking</param>
	/// <param name="flags">Autonomy flags? 0x32 by default</param>
	/// <param name="name">Name on pie menu</param>
	/// <param name="instanceId">Instance ID of the interaction. Will search in Private -> Semiglobal -> Global scopes.</param>
	void AddCheatInteraction(std::vector<cTSInteraction*>* interactions, cTSPerson* person, cTSObject* object, InteractionType immediate, short flags, const char* name, short instanceId) {
		typedef void func(std::vector<cTSInteraction*>* interactions, cTSPerson* person, cTSObject* object, InteractionType immediate, short flags, const char* name, short instanceId);
		return ((func*)0x008a4fc0)(interactions, person, object, immediate, flags, name, instanceId);
	}

	cTSMainToolbar* MainToolbar() {
		typedef cTSMainToolbar* func(void);
		return ((func*)0x00799a38)();
	}

	cRZLanguageManager* LanguageManager() {
		typedef cRZLanguageManager* func(void);
		return ((func*)0x00799cfa)();
	}
}