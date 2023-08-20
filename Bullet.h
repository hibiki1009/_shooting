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

	int damage;				// �_���[�W

	float angle;			// �p�x
	float acceleration;		// ���x�̕ω���
	float angulVelocity;	// �p�x�̕ω���
	float speed;			// �X�s�[�h
	

	bool firing;
	bool E_shoot;

	int move;

	float x, y;

};

