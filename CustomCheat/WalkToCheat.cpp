#include "pch.h"
#include "WalkToCheat.h"
#include "../TS2Hook/Encoding.h"
#include <sstream>

const char* WalkToCheat::Name() {
	return "walkTo";
}

const char* WalkToCheat::Description(void* commandHelpType) {
	return "Makes the active Sim route to the first TS2Hook Test Object it can find on the lot.";
}

void WalkToCheat::Execute(nGZCommandParser::cArguments* arguments) {
    TS::cTSGlobals* pGlobals = TS::Globals();
    TS::cEdithObjectModule* pObjectManager = pGlobals->ObjectManager();
    TS::cTSPerson* pSelectedPerson = pObjectManager->GetSelectedPerson();
    TS::cTSObject* pSelectedPersonAsObject = pSelectedPerson->AsEdithObject();
    int selectedPersonID = pSelectedPersonAsObject->GetID();
    // Behavior basically defines the scope of where the game will look for the BHAV. So in its private, semiglobal or global.
    TS::cTSBehavior* pBehavior = pSelectedPersonAsObject->GetBehavior();
    pSelectedPersonAsObject->RunTreeByName(pBehavior, selectedPersonID, "DEBUG - Force Twins", 0, 0, 0, 0);
}