#include "pch.h"
#include "Drawing.h"
#include <d3dx9.h>

LPD3DXFONT font = NULL;

void Drawing::DrawTxt(LPCWSTR string, Color color, int left, int top) {
    if (font == NULL)
        return;
    RECT rct; //Font
    rct.left = left;
    rct.right = 800;
    rct.top = top;
    rct.bottom = 800;
    font->DrawTextW(NULL, string, -1, &rct, 0, D3DCOLOR_ARGB(color.R, color.G, color.B, color.A));
}

void Drawing::OnReset(LPDIRECT3DDEVICE9 pDevice)
{
    if (font != NULL)
    {
        font->OnLostDevice();
        font->OnResetDevice();
        //font->Release();
        //font = NULL;
    }
}

void Drawing::OnDraw(LPDIRECT3DDEVICE9 pDevice)
{
    if (font == NULL)
    {
        HRESULT res = D3DXCreateFont(pDevice, 17, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"), &font);
        if (res != S_OK)
            font = NULL;
    }
}