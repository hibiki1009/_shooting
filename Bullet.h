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
	Bullet(float l_x, float l_y, bool _Enemyshoot);
	void Update();
	void Draw();
	int GetDamage();
	Location SetLocation(SphereCollider* spherecollider);
private:

	int damage;				// ダメージ

	float angle;			// 角度
	float acceleration;		// 速度の変化量
	float angulVelocity;	// 角度の変化量
	float speed;			// スピード
	

	bool firing;
	bool E_shoot;

	int move;

	float x, y;

};

