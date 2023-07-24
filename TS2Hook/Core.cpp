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

cRZString::cRZString()
{
    typedef void __stdcall func();
    ((func*)0x00404e47)();
}

cRZString::cRZString(const char* str)
{
    typedef void __stdcall func(const char* str);
    ((func*)0x00401272)(str);
}

cTSString::cTSString(short instanceID, int stringID, int groupID, int unknown)
{
    typedef void __stdcall func(short instanceID, int stringID, int groupID, int unknown);
    ((func*)0x00cd4070)(instanceID, stringID, groupID, unknown);
}

cTSString::~cTSString()
{
    free(str);
}

cRZString::~cRZString()
{
    free(str);
}

cRZMessage2Standard::cRZMessage2Standard()
{
    typedef void __stdcall func();
    ((func*)0x0040fb17)();
}

namespace RZ {
    cGZMessageServer2* MS2() {
        typedef cGZMessageServer2* __stdcall func();
        return ((func*)0x00ec1d3f)();
    }
}