#include "pch.h"
#include "CustomInteractionScript.h"
#include "../TS2Hook/Input.h"

void CustomInteractionScript::OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim, bool debug) {
	if (debug)
		return;
	TS::cTSGlobals* pGlobals = TS::Globals();
	if (pGlobals == nullptr)
		return;
	TS::cEdithObjectModule* pObjectMgr = pGlobals->ObjectManager();
	if (pObjectMgr == nullptr)
		return;
	// GUID for TS2Hook - Interaction - Steal Object, our global controller that contains our interaction tree in its private scope.
	TS::cTSObject* pInteractionObject = pObjectMgr->GetObjectByGUID(0xE0F98CA8);
	if (pInteractionObject == nullptr)
		return;
	TS::cTSBehavior* pBehavior = pInteractionObject->GetBehavior();
	TS::cTSObject* pPersonAsObject = testSim->person->AsEdithObject();
	short objectId = testSim->object->GetID();
	// Run the Interaction - Steal TEST check tree on the clicked object.
	if (!pPersonAsObject->RunTree(pBehavior, objectId, 0x1003, 0, 0, 0, 0))
		return;
	// Check tree passed, add Interaction - Steal. We have to pass our interaction controller here rather than the object we clicked as the target.
	TS::AddCheatInteraction(interactions, testSim->person, pInteractionObject, TS::InteractionType::Blocking, 0x32, "Steal", 0x1002);
	// Get the interaction we just added.
	TS::cTSInteraction* newInteraction = interactions->back();
	// Change the target object so that the interaction runs on the object we clicked, rather than the one with the interaction.
	newInteraction->SetTargetObject(testSim->object);
	// Pass the ID of the object we clicked to the interaction as parameter 0. The BHAV tree swaps the stack object to param 0 first thing (Would be nice to automate this)
	short stackVars[] = { objectId, 0, 0, 0 };
	newInteraction->SetStackVars(stackVars);
	// This is hacky, but works to prevent any clashes with private/semiglobal/global scope by technically running the interaction from a separate object.
}