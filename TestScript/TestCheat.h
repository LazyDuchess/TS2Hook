#pragma once
#include "../TS2Hook/Game.h"

class TestCheat : public TS::cCheatCommand {
public:
	char* Name();
	char* Description(void* commandHelpType);
	void Execute(void* arguments);
};