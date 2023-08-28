#include "Title.h"
#include"PAD_INPUT.h"
#include"GameMain.h"
#include"common.h"
#include"Ranking.h"

#define FADE_TIME 100

Title::Title()
{
	bright = 0;
	enter_se = LoadSoundMem("Sound/SE/enter.mp3");
	menu_font = LoadFontDataToHandle("font/funwari-round_s120.dft");
	cursor_move_se = LoadSoundMem("Sound/SE/Cursor_Move.mp3");
	enter_flg = false;
	// セレクト値をプレイにする
	select_menu = static_cast<int>(MENU::PLAY);
	// フェードアウト用変数
	fade_counter = 0;
	fade_Mng = 1;
	// 明るさをリセット 0 0 0は黒
	SetDrawBright(0, 0, 0);

	Title_Num = 0;
	Num_Update = 1;
	WaitTime = 0;
	cursorX = 130;
	cursorY = 420;


	test = LoadGraph("images/Title/error.avi");
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
	DeleteSoundMem(cursor_move_se);
}

AbstractScene* Title::Update()
{
	/*printfDx("  %d  ", test);*/
	if (fade_counter < FADE_TIME)
	{
		fade_counter = fade_counter+ fade_Mng;
	}

	// float変換fadeで割った値をintにし、brightとする
	bright = static_cast<int>((static_cast<float>(fade_counter) / FADE_TIME * 255));

	if (++WaitTime % 10 == 0) {
		Title_Num++;
	}
	if (Title_Num >= 6) {
		Title_Num = 0;
	}

	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_DOWN)&& enter_flg==false) {
		PlaySoundMem(cursor_move_se, DX_PLAYTYPE_BACK, TRUE);
		// メニュー選択肢を一つ次に移動
			// PlayからHelpなら(0+1) % 4 = 1 HelpからRANKINGなら (1+1) % 4 = 2 EXIT　(3+1) % 4 = 0
		select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);

	}
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_UP) && enter_flg == false) {
		PlaySoundMem(cursor_move_se, DX_PLAYTYPE_BACK, TRUE);
		// メニュー選択肢を一つ前に移動  Play　(0-1+4) % 4 = 3(EXIT)
		select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);

	}

	// select_menuをMENUクラスに変換
	MENU current_selection = static_cast<MENU>(select_menu);

	
		
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_B)) {
		enter_flg = true;
		fade_Mng = -1;
		fade_counter = FADE_TIME - 1;
		PlaySoundMem(enter_se, DX_PLAYTYPE_BACK, TRUE);
	}
	if (enter_flg == true) {
		switch (current_selection)
		{
		case Title::MENU::PLAY:

			if (bright < 0) {
				return new GameMain();
			}
			break;

		case Title::MENU::HELP:
			printfDx("未実装な機能です。\n");
			break;

		case Title::MENU::RANKING:
			if (bright < 0) {
				return new Ranking(0);
			}
			break;

		case Title::MENU::EXIT:
			printfDx("未実装な機能です。\n");
			break;
		}
	}
	return this;
}

	

void Title::Draw() const
{
	SetDrawBright(bright, bright, bright);
	

	
	
	
	DrawGraph(0, 0, T_images[Title_Num], false);
	/*PlayMovie("images/Title/error.ogv", 1, DX_MOVIEPLAYTYPE_NORMAL);*/

	for (int i = 0; i < static_cast<int>(MENU::MENU_SIZE); i++)
	{
		// 文字列の最小Y座標
		const int base_y = 350;

		// 文字列のY座標間隔
		const int margin_y = 100;

		// 文字色
		int color = 0xcccccc;
		// 文字外枠色
		int border_color = 0x00FF00;

		// 透明度
		int transparency = 180;


		// カーソルが合っている場合、文字色と文字外枠色を反転させる
		if (select_menu == i) {
			color = ~color;
			border_color = ~border_color;
			// カーソルがあっているなら透明度なし
			transparency = 255;
		}

		//アルファブレンディングする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparency);
		// 座標　サイズ　色　フォントハンドルとか色々決めれるやつ
		DrawExtendStringToHandle(200, i * margin_y + base_y, 0.5, 0.5, menu_items[i], color, menu_font, border_color);
		// ブレンド処理
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

float Title::inputX() {
	return round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100;
}

float Title::inputY() {
	return round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100;
}


