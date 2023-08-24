#include "UI.h"
#include"DxLib.h"

UI::UI()
{
	score = 0;
	life = 3;
	hp = 50;
	hp_Img = LoadGraph("images/UI/circle2.png");
	hp_Img2 = LoadGraph("images/UI/gauge.bmp");
	hp_mng = hp;
	WaitTime = 0;
}

void UI::Update()
{
	
	if (++WaitTime % 5 == 0) {

	}
}

void UI::Draw()
{
	/*DrawCircleGauge(1200, 120, hp_mng * 1.5, hp_Img2, 0, 0.4);*/
	DrawCircleGauge(1200,120,hp*1.5,hp_Img,0,0.4);
	

	DrawFormatString(1190, 110, 0x000000, "%d", hp);
	DrawFormatString(1190, 110, 0x000000, "%d", hp); 

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

void UI::SetHp(int _hp)
{
	hp = _hp;
}

void UI::SetP_location(float _x, float _y)
{
	x = _y;
	y = _y;
}
