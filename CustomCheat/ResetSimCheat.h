#pragma once
#include "../TS2Hook/Game.h"

class ResetSimCheat : public TS::cCheatCommand {
public:
	const char* Name();
	const char* Description(void* commandHelpType);
	void Execute(nGZCommandParser::cArguments* arguments);
	int HandlesAllArguments();
};