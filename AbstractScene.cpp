#include "AbstractScene.h"
#include "DxLib.h"
#include "common.h"

int AbstractScene::GetDrawCenterX(const char* string, int font_handle) const
{
	//画面の中心に
	const int w = SCREEN_WIDTH / 2 - GetDrawFormatStringWidthToHandle(font_handle, string) / 2;
	return w;
}
