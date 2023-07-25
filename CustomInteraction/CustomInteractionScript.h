#pragma once
#include "../TS2Hook/Script.h"

class CustomInteractionScript : public Script {
public:
	void OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim, bool debug);
	int GetID();
};