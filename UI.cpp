#include "UI.h"
#include"DxLib.h"

UI::UI()
{
	font = LoadFontDataToHandle("font/funwari-round_title.dft");
	score = 0;
	life = 3;
	hp_Img = LoadGraph("images/UI/circle2.png");
	hp_Img2 = LoadGraph("images/UI/gauge.bmp");
	hp_mng = hp;
}

void UI::Update()
{

}

void UI::Draw()
{
	/*DrawCircleGauge(1200, 120, hp_mng * 1.5, hp_Img2, 0, 0.4);*/
	DrawCircleGauge(1200,120,hp*2,hp_Img,0,0.4);

	DrawFormatString(1190, 110, 0x000000, "%d", hp);

	DrawFormatString(200, 50, 0x000000, "Point: %d", score);
	DrawFormatString(100, 150, 0x000000, "Life: %d", life);
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
