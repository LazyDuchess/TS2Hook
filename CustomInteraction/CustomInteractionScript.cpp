#include "pch.h"
#include "CustomInteractionScript.h"
#include "../TS2Hook/Input.h"

const char* interactionName = "Reset Object";
const char* interactionNameSpanish = "Reiniciar Objeto";

void CustomInteractionScript::OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim, bool debug) {
    if (debug)
        return;

	TS::cTSGlobals* globals = TS::Globals();
	if (globals == nullptr)
		return;
	TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
	if (objectMgr == nullptr)
		return;
	/*
	std::vector<TS::cTSObject*>* objects = objectMgr->GetObjects();
	TS::cTSObject* testObject = nullptr;

	for (auto object : *objects)
	{
		if (object == nullptr)
			continue;
		TS::cTSObjectSelector* selector = object->GetSelector();
		if (selector == nullptr)
			continue;
		if (selector->GetGUID() == 0x53F1F7DC)
		{
			testObject = object;
			break;
		}
	}

	if (testObject == nullptr)
		return;
	*/
	TS::cTSObject* testObject = objectMgr->GetObjectByGUID(0x53F1F7DC);
	if (testObject == nullptr)
		return;

	TS::AddCheatInteraction(interactions, testSim->person, testObject, TS::InteractionType::Blocking, 0x32, "Walk To", 0x1006);
	TS::cTSInteraction* lastInteraction = interactions->back();
	lastInteraction->SetTargetObject(testSim->object);
	short stackVars[] = { testSim->object->GetID(), 0, 0, 0 };
	lastInteraction->SetStackVars(stackVars);
	//lastInteraction->StackObjectID = testSim->object->GetID();
		/*
    const char* localizedName = interactionName;
    if (TS::LanguageManager()->GetCurrentLanguage() == Language::Spanish)
        localizedName = interactionNameSpanish;
    TS::AddCheatInteraction(interactions, testSim->person, testSim->object, TS::InteractionType::Immediate, 0x32, localizedName, 0x2da);*/
}