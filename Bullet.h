#pragma once
#include "SphereCollider.h"
#include<vector>
#include"Player.h"

//typedef struct Bullet_Vector {
//	float x, y;
//}B_Vector;

class Bullet:public SphereCollider
{

public:

	void Bullet_Firing();
	Bullet(float l_x, float l_y);
	void Update();
	void Draw();
	int GetDamage();
	Location SetLocation(SphereCollider* spherecollider);
	float Getx();
	float Gety();

private:

	float angle;			// 角度
	float acceleration;		// 速度の変化量
	float angulVelocity;	// 角度の変化量
	float speed;			// スピード
	int damage;				// ダメージ

	bool firing;

	int move;

	float x, y;

};

