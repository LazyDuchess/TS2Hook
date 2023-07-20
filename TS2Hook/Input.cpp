#include "pch.h"
#include "Input.h"
#include "Core.h"

namespace Input {
	bool GameFocused()
	{
		HWND window = GetGameWindow();
		if (window == NULL)
			return false;
		return GetActiveWindow() == window;
	}
	// Checks if a key was just pressed this frame.
	bool KeyPressed(int vKey)
	{
		if (!GameFocused())
			return false;
		return ((GetAsyncKeyState(vKey) & 0x8001) == 0x8001);
	}
	// Checks if a key is down.
	bool KeyDown(int vKey)
	{
		if (!GameFocused())
			return false;
		return GetAsyncKeyState(vKey) & 0x8000;
	}
}