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

	float angle;			// �p�x
	float acceleration;		// ���x�̕ω���
	float angulVelocity;	// �p�x�̕ω���
	float speed;			// �X�s�[�h
	int damage;				// �_���[�W

	bool firing;

	int move;

	float x, y;

};

