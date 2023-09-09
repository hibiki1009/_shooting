#pragma once
#include"AbstractScene.h"
#include"DxLib.h"

class Title :public AbstractScene {
private:

	enum class MENU
	{
		PLAY,
		HELP,
		RANKING,
		EXIT,
		MENU_SIZE
	};
	// 列挙型クラスをint変換。表示用
	const char* menu_items[static_cast<int>(MENU::MENU_SIZE)] = {
		"きどうする",
		"システムについて",
		"きろくをみる",
		"おわる"
	};
	int bright;

	int T_images[7];
	int Title_Num;
	int Num_Update;
	int WaitTime;

	int cursorX;
	int cursorY;
	//フェード用カウンタ
	int fade_counter;
	int fade_Mng;
	// 選択しているメニュー
	int select_menu;
	//選択SE用サウンドハンドル
	int select_se;
	//決定SE用サウンドハンドル
	int decision_se;

	// フォントハンドル
	int menu_font;

	bool enter_flg;
public:
	// コンストラクタ
	Title();
	// デストラクタ
	virtual ~Title();

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
	float inputX();
	float inputY();

};