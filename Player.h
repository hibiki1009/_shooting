#pragma once
#include"SphereCollider.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include <math.h>
#include"Bullet.h"

// メモ
// プレイヤーがバレットを持つように設計しなおす
// 出来るだけ関数の戻り値を使って書く

class Player:public CharaBase
{
private:
	int HitBullet;		// テスト用
	int score;
	float Speed;			// プレイヤースピード
	float Pr;
	float start;



public:
	/*Bullet* bullet;*/
	static int BulletFlg;		// 1上 2右 3下 4左
	//static int Px, Py;	// プレイヤーの座標

	int test = 0;
	Player();
	~Player();

	// overrideは関数の処理を上書きすることができる
	void Update() override;
	void Draw() const override;

	// コントローラの入力を返す
	float inputX();
	float inputY();

	// Playerの移動に関する処理
	void PlayerMove();
	/*void Bullet_Move();*/
};

