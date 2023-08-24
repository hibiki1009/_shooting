#pragma once
class UI
{
public:
	// コンストラクタ
	UI();
	void Update();
	void Draw();

	// GameMainからスコアを持ってくる　スコアエフェクト＆アニメーション、描画を行う
	void Scor_Anim();
	// スコアをセットする
	void SetScore(int _score);
	void SetLife(int life);
private:
	int score;
	int life;
};

