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

	Bullet(float l_x, float l_y, bool _Enemyshoot, float _Radian, float b_speed);
	~Bullet();
	void Update();
	void Draw();
	int GetDamage();
	virtual float inputX();
	virtual float inputY();
	float Distance_Line_Segment();

	float GetLocationX();
	float GetLocationY();



private:
	float Radian;
	int WaitTime;
	int test;

	int damage;				// �_���[�W

	float angle;			// �p�x
	float acceleration;		// ���x�̕ω���
	float angulVelocity;	// �p�x�̕ω���
	float Bullet_speed;			// �X�s�[�h
	int color;

	bool firing;
	bool E_shoot;

	int move;

	int moveX;
	int moveY;
	
	bool Aim_flgX;
	bool Aim_flgY;

};

