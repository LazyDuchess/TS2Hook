#include "pch.h"
#include "UI.h"

namespace nTSUI {
	void MessageBoxOK(cIGZString* message) {
		typedef void func(cIGZString* message);
		((func*)0x005bbcca)(message);
	}
}