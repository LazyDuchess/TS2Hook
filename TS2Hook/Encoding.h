#pragma once
#include <string>
#include "Types.h"
namespace Encoding {
	// Converts an UTF-8 string to Unicode.
	DllExport std::wstring UTF8ToWString(const std::string& str);
	// Converts an Unicode string into UTF-8.
	DllExport std::string WStringToUTF8(const std::wstring& wstr);
}