#include "UI.h"
#include"DxLib.h"

UI::UI()
{
	score = 0;
	life = 3;
}

void UI::Update()
{
}

void UI::Draw()
{
	DrawFormatString(20, 0, 0x000000, "%d", score);
	DrawFormatString(20, 50, 0x000000, "%d", life);
}

void UI::Scor_Anim()
{
}

void UI::SetScore(int _score)
{
	score = _score;
}

void UI::SetLife(int _life) 
{
	life = _life;
}
