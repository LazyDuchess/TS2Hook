#pragma once
#include "Types.h"
#include "Game.h"
class DllExport Script {
public:
	virtual void Update();
	virtual void Draw();
	virtual void OnInit();
	virtual void OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim);
};