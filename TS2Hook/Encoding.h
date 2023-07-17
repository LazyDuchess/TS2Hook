#pragma once
#include <string>
#include "Types.h"
namespace Encoding {
	DllExport std::wstring UTF8ToWString(const std::string& str);
	DllExport std::string WStringToUTF8(const std::wstring& wstr);
}