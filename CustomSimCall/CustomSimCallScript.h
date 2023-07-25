#pragma once
#include "../TS2Hook/Script.h"

class CustomSimCallScript : public Script {
public:
	int GetID();
	EdithReturnValue OnEdithCall(cTSTreeStackElem* stack, XPrimParam* primitive);
};