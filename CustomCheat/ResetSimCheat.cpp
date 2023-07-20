#include "pch.h"
#include "ResetSimCheat.h"
#include "../TS2Hook/Encoding.h"
#include <sstream>
#include <iostream>

const char* ResetSimCheat::Name() {
	return "resetSim";
}

const char* ResetSimCheat::Description(void* commandHelpType) {
	return "Usage: resetSim <First Name> <Last Name> or resetSim * to reset everyone.";
}

int ResetSimCheat::HandlesAllArguments() {
	return 1;
}

void ResetAllSims()
{
	TS::cTSGlobals* globals = TS::Globals();
	if (globals != nullptr)
	{
		TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
		if (objectMgr != nullptr)
		{
			auto sims = objectMgr->GetSims();
			for (auto sim : *sims)
			{
				if (sim != nullptr)
				{
					// Cleanup is the same reset procedure used in simantics errors. Reset() is callable by simantics, and not nearly as good at cleaning up.
					sim->AsEdithObject()->Cleanup();
					//sim->AscTSTreeSim()->Reset();
				}
			}
		}
	}
}

std::wstring GetFullName(TS::cTSObjectSelector* selector)
{
	cRZString firstName = cRZString();
	cRZString lastName = cRZString();

	selector->GetCatalogName(&firstName);
	selector->GetCatalogDescription(&lastName);

	std::wstring wFirstName = firstName.GetWString();
	std::wstring wLastName = lastName.GetWString();

	std::wstringstream stream;
	stream << wFirstName << " " << wLastName;
	std::wstring result(stream.str());

	return result;
}

void ResetSimMatchingFullname(std::wstring fullName)
{
	TS::cTSGlobals* globals = TS::Globals();
	if (globals != nullptr)
	{
		TS::cEdithObjectModule* objectMgr = globals->ObjectManager();
		if (objectMgr != nullptr)
		{
			auto sims = objectMgr->GetSims();
			for (auto sim : *sims)
			{
				if (sim != nullptr)
				{
					auto selector = sim->AsEdithObject()->GetSelector();
					std::wstring selectorFullName = GetFullName(selector);

					if (selectorFullName.length() == fullName.length() && _wcsnicmp(selectorFullName.c_str(), fullName.c_str(), selectorFullName.length()) == 0)
					{
						sim->AsEdithObject()->Cleanup();
						return;
					}
				}
			}
		}
	}
}

void ResetSimCheat::Execute(nGZCommandParser::cArguments* arguments) {
	if (arguments->count == 0)
		return;

	std::wstringstream stream;
	for (int i = 0; i < arguments->count; i++)
	{
		std::wstring currentArgument = Encoding::UTF8ToWString((*arguments)[i + 1]);
		stream << currentArgument;
		if (i != arguments->count - 1)
			stream << " ";
	}
	std::wstring result(stream.str());

	if (result.length() == 1 && _wcsnicmp(L"*", result.c_str(), 1) == 0)
	{
		ResetAllSims();
		return;
	}

	ResetSimMatchingFullname(result);
}