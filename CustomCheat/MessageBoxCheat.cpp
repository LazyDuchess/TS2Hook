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
	if (arguments->count < 2)
		return;
	cRZString boxTitle = cRZString((*arguments)[1]);
	cRZString boxMessage = cRZString((*arguments)[2]);
	auto toolbar = TS::MainToolbar();
	auto result = toolbar->MessageDialog(&boxMessage, &boxTitle, TS::DialogType::YesNo);
	if (result == TS::DialogResult::Yes)
	{
		// do something
	}
}