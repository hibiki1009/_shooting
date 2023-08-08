#pragma once
#include"SphereCollider.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include <math.h>

class Player:public CharaBase
{
private:
	

	int HitBullet;		// テスト用

	int score;
	
	float Speed;			// プレイヤースピード
	float Pr;
	
	float start;


public:
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
};

