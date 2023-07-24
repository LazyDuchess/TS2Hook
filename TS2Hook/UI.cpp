#include "pch.h"
#include "UI.h"

namespace nTSUI {
	void MessageBoxOK(cIGZString* message) {
		typedef void __stdcall func(cIGZString* message);
		((func*)0x005bbcca)(message);
	}
}