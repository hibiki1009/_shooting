#include "common.h"
#include"DxLib.h"

#include"AbstractScene.h"
#include"SceneManager.h"

#include"GameMain.h"
#include"FPS.h"
#include"PAD_INPUT.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("shooting");		// タイトルを設定
	ChangeWindowMode(true);					// ウィンドウモードで起動

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);// サイズ
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	CreateFontToHandle(NULL, 20, 3, DX_FONTTYPE_ANTIALIASING);// フォント設定

	if (DxLib_Init() == -1) {
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager scene = (dynamic_cast<AbstractScene*>(new GameMain()));// 初めのシーンをsceneにキャスト

	FPS FPSct(FRAMERATE, UPDATETIME);// フレームレート設定

	// ゲームループ
	while (ProcessMessage() == 0 && scene.Update() != nullptr) {// シーン中の値が空になったら終了

		PAD_INPUT::UpdateInput();			// PADの入力更新
		ClearDrawScreen();					// 画面の初期化

		scene.Draw();						// 現在のシーンを描画する

		FPSct.All();						// FPS処理をまとめたもの

		ScreenFlip();						// 裏画面の内容を表に表示する
	}
	DxLib_End();
	return 0;
}