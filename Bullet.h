#pragma once
#include "SphereCollider.h"
#include<vector>
#include <corecrt.h>
#include"Player.h"
#include<math.h>

//typedef struct Bullet_Vector {
//	float x, y;
//}B_Vector;

class Bullet:public SphereCollider
{

public:

	Bullet(float l_x, float l_y, bool _Enemyshoot, float _Radian);
	~Bullet();
	void Update();
	void Draw();
	int GetDamage();
	void SET_P_Distanse(float _x,float _y);
	virtual float inputX();
	virtual float inputY();
	float Distance_Line_Segment();

private:
	float Radian;
	int WaitTime;
	int test;

	int damage;				// ダメージ

	float angle;			// 角度
	float acceleration;		// 速度の変化量
	float angulVelocity;	// 角度の変化量
	float speed;			// スピード
	

	bool firing;
	bool E_shoot;

	int move;

	int moveX;
	int moveY;
	
	bool Aim_flgX;
	bool Aim_flgY;

};

