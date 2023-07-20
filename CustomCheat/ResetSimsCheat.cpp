#include "pch.h"
#include "ResetSimsCheat.h"
#include "../TS2Hook/Encoding.h"
#include <sstream>

const char* ResetSimsCheat::Name() {
	return "resetSims";
}

const char* ResetSimsCheat::Description(void* commandHelpType) {
	return "Resets all Sims in the current lot.";
}

void ResetSimsCheat::Execute(void* arguments) {
	TS::cTSGlobals* globals = TS::Globals();
	if (globals != nullptr)
	{
		TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
		if (objectMgr != nullptr)
		{
			auto sims = objectMgr->GetSims();
			for (auto sim : *sims)
			{
				if (sim != nullptr)
				{
					// Cleanup is the same reset procedure used in simantics errors. Reset() is callable by simantics, and not nearly as good at cleaning up.
					sim->AscTSTreeSim()->Cleanup();
					//sim->AscTSTreeSim()->Reset();
				}
			}
		}
	}
}