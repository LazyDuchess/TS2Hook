#include "pch.h"
#include "CustomInteractionScript.h"
#include "../TS2Hook/Input.h"

const char* interactionName = "Reset Object";
const char* interactionNameSpanish = "Reiniciar Objeto";

void CustomInteractionScript::OnBuildUserDirectedInteractionMenu(std::vector<TS::cTSInteraction*>* interactions, TS::cEdithObjectTestSim* testSim) {
    if (Input::KeyDown(VK_SHIFT))
        return;
    const char* localizedName = interactionName;
    if (TS::LanguageManager()->GetCurrentLanguage() == Language::Spanish)
        localizedName = interactionNameSpanish;
    TS::AddCheatInteraction(interactions, testSim->person, testSim->object, TS::InteractionType::Immediate, 0x32, localizedName, 0x2da);
}