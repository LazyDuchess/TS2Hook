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
	virtual void* QueryInterface(int unk, void** unk2) = 0;
public:
	virtual void AddRef() = 0;
	virtual int Release() = 0;
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

// This is likely NOT it.
class cRZString {
public:
	// A Rizzo UTF-8 string.
	DllExport cRZString();
	char* str;
	// Converts the UTF-8 string to Unicode.
	std::wstring GetWString() {
		return Encoding::UTF8ToWString(std::string(str));
	}
	std::string GetString() {
		return std::string(str);
	}
private:
	virtual void placeholder() {};
	int unk1;
	int unk2;
	int unk3;
};

// Returns the game window.
DllExport HWND GetGameWindow();