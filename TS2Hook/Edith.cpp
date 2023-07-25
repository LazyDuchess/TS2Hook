#include "pch.h"
#include "Edith.h"

short XPrimParam::GetShort(int offset) {
	return *(short*)(&(operand[offset]));
}

int XPrimParam::GetInt(int offset) {
	return *(int*)(&(operand[offset]));
}

char XPrimParam::GetChar(int offset) {
	return this->operand[offset];
}