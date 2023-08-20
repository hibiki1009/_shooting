#include "Title.h"
#include"PAD_INPUT.h"
#include"GameMain.h"
#include"common.h"

Title::Title()
{
	Title_Num = 0;
	Num_Update = 1;
	WaitTime = 0;
	cursorX = 130;
	cursorY = 420;
	// タイトル画面アニメーション
	T_images[0] = LoadGraph("images/Title/Title1.PNG", false);
	T_images[1] = LoadGraph("images/Title/Title2.PNG", false);
	T_images[2] = LoadGraph("images/Title/Title3.PNG", false);
	T_images[3] = LoadGraph("images/Title/Title4.PNG", false);
	T_images[4] = LoadGraph("images/Title/Title5.PNG", false);
	T_images[5] = LoadGraph("images/Title/Title6.PNG", false);
	T_images[6] = LoadGraph("images/Title/Title7.PNG", false);
}

Title::~Title()
{
}

AbstractScene* Title::Update()
{

	if (++WaitTime % 10 == 0) {
		Title_Num++;
	}
	if (Title_Num >= 6) {
		Title_Num = 0;
	}

	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_DOWN)) {
		cursorY = cursorY +100;
		cursorX = cursorX - 20;
		if (cursorY > 620) {
			cursorX = 130;
			cursorY = 420;
		}
	}
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_UP)) {
		cursorY = cursorY - 100;
		cursorX = cursorX + 20;
		if (cursorY < 420) {
			cursorX = 90;
			cursorY = 620;
		}
	}

	if (cursorY==420 && PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_B)) {
		return new GameMain;
	}
	return this;
}

void Title::Draw() const
{
	
	DrawGraph(0, 0, T_images[Title_Num], false);
	DrawBox(cursorX, cursorY, cursorX + 10, cursorY + 10, 0xff0000, TRUE);
	SetFontSize(50);
	DrawFormatString(150, 400, 0xffffff, "きどうする。");
	DrawFormatString(130, 500, 0xffffff, "きろくを確認する。");
	DrawFormatString(110, 600, 0xffffff, "また明日がんばる");
}

float Title::inputX() {
	return round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100;
}

float Title::inputY() {
	return round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100;
}
