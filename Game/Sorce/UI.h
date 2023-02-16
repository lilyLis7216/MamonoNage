#pragma once

#include"DxLib.h"

class UI final
{
	static void UIBox(int x1, int x2, int y1, int y2, int frameSize, int mainCr, int frameCr);
	static void UIText(int x, int y, int color, const char* str);
};

