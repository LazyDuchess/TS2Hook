#pragma once
#include "Types.h"
#include <d3d9.h> 

namespace Drawing {
	struct DllExport Color {
		byte R;
		byte G;
		byte B;
		byte A;
		Color(byte r, byte g, byte b) : Color(r,g,b,255) {
		}
		Color(byte r, byte g, byte b, byte a) {
			R = r;
			G = g;
			B = b;
			A = a;
		}
	};

	void DllExport DrawTxt(LPCWSTR string, Color color, int left, int top);
	void OnDraw(LPDIRECT3DDEVICE9 pDevice);
	void OnReset(LPDIRECT3DDEVICE9 pDevice);
}