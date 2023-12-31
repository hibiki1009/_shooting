#pragma once

//デフォルトの抽象シーンクラス
//ユーザーはこれを継承してシーンを実装すると楽
class AbstractScene {

protected:

	//画像
	int background_image;

	//SE&BGM
	int background_music;
	int gamemain_music;

	int cursor_move_se;
	int enter_se;

	int title_font;

	//
	short stage_num = 0;

private:
	int num = 0;
	void a() {
		num = 0;
	}

public:
	//デストラクタ
	virtual ~AbstractScene() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw()const = 0;//インターフェイスクラス

	int GetDrawCenterX(const char* string, int font_handle)const;
	//interface（インターフェイス）は、
	//クラスがどのようなメソッドを持っているのかをあらかじめ定義する、
	//いわば設計書のような存在です。 クラスとは異なり、具体的な処理内容を記述せず、
	//メソッドの引数や戻り値だけを定義します。

};
