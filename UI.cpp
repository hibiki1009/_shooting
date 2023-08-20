#include "UI.h"
#include"DxLib.h"

UI::UI()
{
	score = 0;
}

void UI::Update()
{
}

void UI::Draw()
{
	DrawFormatString(0, 0, 0x000000, "%d", score);
}

void UI::Scor_Anim()
{
}

void UI::SetScore(int _score)
{
	score = _score;
}
