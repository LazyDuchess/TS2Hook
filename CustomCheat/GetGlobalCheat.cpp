#include "pch.h"
#include "GetGlobalCheat.h"
#include "../TS2Hook/Encoding.h"

const char* GetGlobalCheat::Name() {
	return "getGlobal";
}

const char* GetGlobalCheat::Description(void* commandHelpType) {
	return "Usage: <id> Returns Simulator Global";
}

void GetGlobalCheat::Execute(nGZCommandParser::cArguments* arguments) {
	if (arguments->count < 1)
		return;
	std::wstring arg1 = Encoding::UTF8ToWString((*arguments)[1]);
	short globalID = std::stoi(arg1,NULL, 16);
	TS::cTSGlobals* pGlobals = TS::Globals();
	if (pGlobals == nullptr)
		return;
	TS::cTSSimulator* pSimulator = pGlobals->GetSimulator();
	if (pSimulator == nullptr)
		return;
	std::wstring globalValue = std::to_wstring(pSimulator->GetGlobal(globalID));
	MessageBox(NULL, globalValue.c_str(), L"Info", MB_OK);
}