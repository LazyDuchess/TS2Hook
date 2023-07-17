#include "pch.h"
#include "TestCheat.h"

char cheatName[] = "deleteAllObjects";
char cheatDescription[] = "Deletes all objects in the current lot.";

char* TestCheat::Name() {
	return cheatName;
}

char* TestCheat::Description(void* commandHelpType) {
	return cheatDescription;
}

void TestCheat::Execute(void* arguments) {
	TS::cTSGlobals* pGlobals = TS::Globals();
	TS::cEdithObjectModule* pObjectManager = pGlobals->ObjectManager();
	pObjectManager->DeleteAllObjects();
}