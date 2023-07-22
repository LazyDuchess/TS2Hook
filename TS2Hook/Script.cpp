#include "pch.h"
#include "Script.h"

void Script::Update() {}
void Script::Draw() {}
void Script::OnInit() {}
void Script::OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim, bool debug) {}
void Script::OnPreSimulate(TS::cTSSimulator* simulator) {}
void Script::OnSimulatorInit(TS::cTSSimulator* simulator) {}
void Script::OnSimulatorSaveBegin(TS::cTSSimulator* simulator) {}
void Script::OnSimulatorSaveEnd(TS::cTSSimulator* simulator) {}
void Script::OnSimulatorFinishLoading(TS::cTSSimulator* simulator) {}
const char* Script::GetName() { return ""; }
