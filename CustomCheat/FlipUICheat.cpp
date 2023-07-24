#include "pch.h"
#include "FlipUICheat.h"
#include "../TS2Hook/Encoding.h"

const char* FlipUICheat::Name() {
	return "flipUI";
}

const char* FlipUICheat::Description(void* commandHelpType) {
	return "Usage: <id> switches the UI.";
}

void FlipUICheat::Execute(nGZCommandParser::cArguments* arguments) {
	if (arguments->count < 1)
		return;
	std::wstring arg1 = Encoding::UTF8ToWString((*arguments)[1]);
	int arg2 = 0;
	int arg3 = 0;
	if (arguments->count >= 2)
	{
		std::wstring arg2ws = Encoding::UTF8ToWString((*arguments)[2]);
		arg2 = std::stoi(arg2ws, NULL, 0);
	}
	if (arguments->count >= 3)
	{
		std::wstring arg3ws = Encoding::UTF8ToWString((*arguments)[3]);
		arg3 = std::stoi(arg3ws, NULL, 0);
	}
	int uiID = std::stoi(arg1, NULL, 0);
	TS::cTSGameStateController* pGameStateController = TS::GameStateController();
	pGameStateController->FlipUI(uiID, arg2, arg3);
}