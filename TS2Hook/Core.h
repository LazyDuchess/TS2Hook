#pragma once
#include "Types.h"
#include <windef.h>
#include <string>
#include "Encoding.h"

template <typename T>
struct LinkedList {
	struct Node {
		Node* Next;
	    Node* Previous;
		T* Pointer;
		bool IsHead() {
			// Weird
			return (int)Pointer == 0x00000010;
		}
	};
	Node* Head;
	Node* First()
	{
		return Head->Next;
	}
	int Count() {
		int count = 0;
		Node* pNode = Head;
		Node* pNextNode = Head->Next;
		while (!pNextNode->IsHead())
		{
			pNextNode = pNextNode->Next;
			count++;
		}
		return count;
	}
};
class cIGZUnknown {
private:
	virtual void* QueryInterface(int unk, void** unk2) { 
		typedef void* __stdcall func(int unk, void** unk2);
		func* fnPtr = (func*)(*(int*)(((int)(*((int*)this))) + 0x0));
		return fnPtr(unk, unk2);
	};
public:
	virtual void AddRef() {
		typedef void __stdcall func();
		func* fnPtr = (func*)(*(int*)(((int)(*((int*)this))) + 0x4));
		fnPtr();
	}
	virtual int Release() {
		typedef int __stdcall func();
		func* fnPtr = (func*)(*(int*)(((int)(*((int*)this))) + 0x8));
		return fnPtr();
	};
};

enum class Language {
	Unknown,
	English,
	UKEnglish,
	French,
	German,
	Italian,
	Spanish,
	Dutch,
	Danish,
	Swedish,
	Norwegian,
	Finnish,
	Hebrew,
	Russian,
	Portuguese,
	Japanese,
	Polish,
	SimplifiedChinese,
	TraditionalChinese,
	Thai,
	Korean,
	Hindi,
	Arabic,
	Bulgarian,
	Cyrillic,
	Ukranian,
	Czech,
	Greek,
	Hungarian,
	Icelandic,
	Romanian,
	Latin,
	Slovak,
	Albanian,
	Turkish,
	BrazilianPortuguese,
	SwissFrench,
	CanadianFrench,
	BelgianFrench,
	SwissGerman,
	SwissItalian,
	BelgianDutch,
	MexicanSpanish,
	Tagalog,
	Vietnamese
};

class cRZLanguageManager : public cIGZUnknown {
private:
	virtual void Init();
	virtual void Shutdown();
	virtual void AddAvailableLanguage();
	virtual void RemoveAvailableLanguage();
public:
	virtual Language GetCurrentLanguage();
	virtual void SetCurrentLanguage(Language language);
};

class cIGZString : public cIGZUnknown {
public:
	char* str;
	// Converts the UTF-8 string to Unicode.
	std::wstring GetWString() {
		return Encoding::UTF8ToWString(std::string(str));
	}
	std::string GetString() {
		return std::string(str);
	}
};

// This is likely NOT it.
class cRZString : public cIGZString {
public:
	// A Rizzo UTF-8 string.
	DllExport cRZString();
	DllExport cRZString(const char* str);
	DllExport ~cRZString();
	char pad[12];
};

class cTSString : public cIGZString {
public:
	DllExport cTSString(short instanceID, int stringID, int groupID, int unknown = 0x2026960b);
	DllExport ~cTSString();
private:
	char pad[30];
};

// Returns the game window.
DllExport HWND GetGameWindow();

class cGZMessageServer2 : public cIGZUnknown {
private:
	//virtual void fn0();
	//virtual void fn1();
	//virtual void fn2();
public:

};

class cRZMessage2Standard : public cIGZUnknown {
private:
	//virtual void fn0();
	//virtual void fn1();
	//virtual void fn2();
public:
	DllExport cRZMessage2Standard();
};

namespace RZ {
	DllExport cGZMessageServer2* MS2();
}