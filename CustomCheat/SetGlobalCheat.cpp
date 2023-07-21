#include "pch.h"
#include "SetGlobalCheat.h"
#include "../TS2Hook/Encoding.h"

const char* SetGlobalCheat::Name() {
	return "setGlobal";
}

const char* SetGlobalCheat::Description(void* commandHelpType) {
	return "Usage: <id> <value> Modifies a Simulator Global";
}

void SetGlobalCheat::Execute(nGZCommandParser::cArguments* arguments) {
	if (arguments->count < 2)
		return;
	std::wstring arg1 = Encoding::UTF8ToWString((*arguments)[1]);
	std::wstring arg2 = Encoding::UTF8ToWString((*arguments)[2]);
	short globalID = std::stoi(arg1, NULL, 16);
	short globalValue = std::stoi(arg2, NULL, 10);
	TS::cTSGlobals* pGlobals = TS::Globals();
	if (pGlobals == nullptr)
		return;
	TS::cTSSimulator* pSimulator = pGlobals->GetSimulator();
	if (pSimulator == nullptr)
		return;
	pSimulator->SetGlobal(globalID, globalValue);
}