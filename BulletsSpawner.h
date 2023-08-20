#pragma once
#include"GameMain.h"
#include"Bullet.h"
#include "common.h"


class BulletsSpawner
{
private:
	float speed;
	float angle;
	float acceleration;			// 速度の変化量
	float angulVelocity;		// 角度の変化量

public:
	/*Bullet* bullets[100];*/
	// 引数にゲームメインシーンのポインタを受け取るSpawnBulletで弾を生成する
	// 弾を発射する	
	/*int Shoot(Bullet* bullet[100]);*/
	/*int Shoot(struct bullet[Bullet_Num]);*/
};

