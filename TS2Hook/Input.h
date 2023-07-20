#pragma once
#include "Types.h"

namespace Input {
	// Checks if a key was just pressed this frame.
	DllExport bool KeyPressed(int vKey);
	// Checks if a key is down.
	DllExport bool KeyDown(int vKey);
}