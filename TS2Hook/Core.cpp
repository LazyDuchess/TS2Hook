#include "pch.h"
#include "Core.h"

HWND gHWND = NULL;

BOOL CALLBACK EnumWindowsCallback(HWND hwnd, LPARAM lParam)
{
    DWORD lpdwProcessId;
    GetWindowThreadProcessId(hwnd, &lpdwProcessId);
    if (lpdwProcessId == lParam)
    {
        gHWND = hwnd;
        return FALSE;
    }
    return TRUE;
}

HWND GetGameWindow()
{
    if (gHWND != NULL)
        return gHWND;
    int pid = GetCurrentProcessId();
    EnumWindows(EnumWindowsCallback, pid);
}