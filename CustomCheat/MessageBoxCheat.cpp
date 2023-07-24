#include "pch.h"
#include "MessageBoxCheat.h"
#include "../TS2Hook/UI.h"
#include "../TS2Hook/Encoding.h"
#include "CustomCheatScript.h"
#include <sstream>

const char* MessageBoxCheat::Name() {
	return "messageBox";
}

const char* MessageBoxCheat::Description(void* commandHelpType) {
	return "Shows a message box.";
}

cRZString* boxMessage = nullptr;

void MessageBoxCheat::Execute(nGZCommandParser::cArguments* arguments) {
	boxMessage = new cRZString((*arguments)[1]);
    CreateThread(nullptr, 0, [](LPVOID) -> DWORD
        {
			
			nTSUI::MessageBoxOK(boxMessage);
			ExitThread(0);
        }, nullptr, 0, nullptr);
	
}