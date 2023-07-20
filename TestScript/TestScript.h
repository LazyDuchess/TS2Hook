#pragma once
#include "../TS2Hook/Script.h"

class TestScript : public Script {
public:
	void Update();
	void Draw();
	void OnInit();
	void OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim);
};