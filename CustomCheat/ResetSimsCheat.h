#pragma once
#include "../TS2Hook/Game.h"

class ResetSimsCheat : public TS::cCheatCommand {
public:
	const char* Name();
	const char* Description(void* commandHelpType);
	void Execute(void* arguments);
};