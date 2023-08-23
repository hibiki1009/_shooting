#pragma once
#include"SphereCollider.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include <math.h>
#include"Bullet.h"



class Player:public CharaBase
{
private:
	int HitBullet;		// テスト用
	int score;
	int hp;
	float Speed;			// プレイヤースピード
	float aim_Speed;		// エイムの感度
	float Pr;
	float start;

	float aim_x;
	float aim_y;
	int aim_img;

public:
	/*Bullet* bullet;*/
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

	float inputRX();
	float inputRY();

	void Aiming();
	// Playerの移動に関する処理
	void PlayerMove();
	/*void Bullet_Move();*/

	float GetAime_x();
	float GetAime_y();

	float getRadian();
	int GetHp();
	void Hit(int _damage)override;
};

