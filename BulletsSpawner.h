#pragma once
#include"Bullet.h"
#include "common.h"
#include"SphereCollider.h"

// クラス宣言
class GameMain;

class BulletsSpawner
{
private:

	float speed;
	float angle;
	float acceleration;			// 速度の変化量
	float angulVelocity;		// 角度の変化量

public:
	// 引数にゲームメインシーンのポインタを受け取るSpawnBulletで弾を生成する
	// 弾を発射する	

	int Shoot(GameMain* gamemain);
};

