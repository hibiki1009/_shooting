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
	void SetHp(int _hp);
	void SetP_location(float _x, float _y);
private:
	int WaitTime;
	int score;
	int life;
	int hp;
	int hp_Img;
	int hp_Img2;

	int hp_mng;


	float x, y;
};

