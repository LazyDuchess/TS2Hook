#pragma once
#include "Types.h"
#include "Game.h"
class DllExport Script {
public:
	// Called every frame.
	virtual void Update();
	// Called every frame, after all of the game rendering is done.
	virtual void Draw();
	// Called on initialization. Register cheats and such here.
	virtual void OnInit();
	// Called when the game is done building the pie menu for the user. Can add interactions using TS::AddCheatInteraction.
	virtual void OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim, bool debug);
	// Called each simulation tick, before objects are simulated.
	virtual void OnPreSimulate(TS::cTSSimulator* simulator);
	// Called when the Simulator is created from scratch. Typically when on a new lot, or when going into neighborhood view as it doesn't have persistent state.
	virtual void OnSimulatorInit(TS::cTSSimulator* simulator);
	// Called when the Simulator begins saving, before any information is written.
	virtual void OnSimulatorSaveBegin(TS::cTSSimulator* simulator);
	// Called when the Simulator is done writing all data to the save.
	virtual void OnSimulatorSaveEnd(TS::cTSSimulator* simulator);
	// Called when the Simulator is done loading saved data. Init will not run if a saved state is loaded.
	virtual void OnSimulatorFinishLoading(TS::cTSSimulator* simulator);
	// Name of this Script.
	virtual const char* GetName();
};