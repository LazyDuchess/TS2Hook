#pragma once
#include "../TS2Hook/Script.h"

class CustomInteractionScript : public Script {
public:
	virtual void OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim);
};