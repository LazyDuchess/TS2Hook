#pragma once
#include "Core.h"
#include "Types.h"

enum class EdithReturnValue {
	Block = 0xFFFFFFFF,
	False = 0x00000000,
	True = 0x00000001,
	Unhandled = 0x00000002
};

class cTSTreeStackElem : public cIGZUnknown {
private:
	//virtual void fn0();
	//virtual void fn1();
	//virtual void fn2();
public:
	virtual short GetRunningObject();
	virtual void SetRunningObject(short objectID);
	virtual short GetRunningOnObject();
	virtual void SetRunningOnObject(short objectID);
private:
	virtual void fn7();
	virtual void fn8();
	virtual void fn9();
	virtual void fn10();
	virtual void fn11();
public:
	virtual short GetObjectID();
	virtual void SetObjectID(short objectID);
};

class XPrimParam {
private:
	virtual void Write();
	virtual void Read();
	virtual void UpgradeVersion();
	virtual void GetCurrentVersion();
	virtual void SwizzleParams();
public:
	char operand[16];
	DllExport char GetChar(int offset);
	DllExport int GetInt(int offset);
	DllExport short GetShort(int offset);
};