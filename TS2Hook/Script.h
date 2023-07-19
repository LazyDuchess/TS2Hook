#pragma once
#include "Types.h"
class DllExport Script {
public:
	virtual void Update();
	virtual void Draw();
	virtual void OnInit();
};