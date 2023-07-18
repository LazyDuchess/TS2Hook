#include "pch.h"
#include "TestCheat.h"

const char* TestCheat::Name() {
	return "testCheat";
}

const char* TestCheat::Description(void* commandHelpType) {
	return "Does something crazy.";
}

void TestCheat::Execute(void* arguments) {
    TS::cTSGameStateController* pGameStateController = TS::GameStateController();
    TS::cTSNeighborhoodInfo* nhInfo = pGameStateController->CurrentNeighborhoodInfo();
	std::wstring hoodType = L"Current Neighborhood Type: ";
	hoodType.append(std::to_wstring(nhInfo->NeighborhoodType()));
	MessageBox(NULL, hoodType.c_str(), L"Info!", MB_OK);
}