#include "pch.h"
#include "SimNameCheat.h"
#include "../TS2Hook/Encoding.h"
#include <sstream>

const char* SimNameCheat::Name() {
	return "simName";
}

const char* SimNameCheat::Description(void* commandHelpType) {
	return "Outputs the name of the selected Sim.";
}

void SimNameCheat::Execute(nGZCommandParser::cArguments* arguments) {
	TS::cTSGlobals* globals = TS::Globals();
	if (globals != nullptr)
	{
		TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
		if (objectMgr != nullptr)
		{
			auto activeSim = objectMgr->GetSelectedPerson();
			auto treeSim = activeSim->AsEdithObject();
			auto selector = treeSim->GetSelector();
			cRZString firstName = cRZString();
			cRZString lastName = cRZString();
			selector->GetCatalogName(&firstName);
			selector->GetCatalogDescription(&lastName);
			MessageBox(NULL, firstName.GetWString().c_str(), L"Info", MB_OK);
			MessageBox(NULL, lastName.GetWString().c_str(), L"Info", MB_OK);
		}
	}
}