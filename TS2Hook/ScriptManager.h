#pragma once
#include "Types.h"
#include "Script.h"

class DllExport ScriptManager
{
public:
	static void Register(Script* script);
	static void Initialize(HMODULE hModule);
	static Script* GetScript(int id);
};