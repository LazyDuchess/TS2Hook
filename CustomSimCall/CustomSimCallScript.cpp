#include "pch.h"
#include "CustomSimCallScript.h"
#include "../TS2Hook/Game.h"
#include "../TS2Hook/Encoding.h"
#include "../TS2Hook/UI.h"

int CustomSimCallScript::GetID() {
	static const int hash = 0xF210E654;
	return hash;
}

EdithReturnValue CustomSimCallScript::OnEdithCall(cTSTreeStackElem* stack, XPrimParam* primitive) {
	auto pGlobals = TS::Globals();
	if (pGlobals == nullptr)
		return EdithReturnValue::False;
	auto pObjectManager = pGlobals->ObjectManager();
	if (pObjectManager == nullptr)
		return EdithReturnValue::False;
	// GetRunningObject is My Object ID.
	auto objectID = stack->GetRunningObject();
	auto pObject = pObjectManager->GetObjectFromID(objectID);
	auto objectStr = Encoding::UTF8ToWString(pObject->GetName());
	objectStr.append(L" - Temp 0 is: ");
	objectStr.append(std::to_wstring(pObject->GetTemp(0)));
	cRZString cstr = cRZString(Encoding::WStringToUTF8(objectStr).c_str());
	nTSUI::MessageBoxOK(&cstr);
	return EdithReturnValue::True;
}