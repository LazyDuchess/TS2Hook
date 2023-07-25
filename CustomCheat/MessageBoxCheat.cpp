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

void MessageBoxCheat::Execute(nGZCommandParser::cArguments* arguments) {
	cRZString boxMessage = cRZString((*arguments)[1]);
	nTSUI::MessageBoxOK(&boxMessage);
}