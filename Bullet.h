#pragma once
#include "SphereCollider.h"
#include<vector>

//typedef struct Bullet_Vector {
//	float x, y;
//}B_Vector;

class Bullet:public SphereCollider
{
private:
		float angle;			// �p�x
		float acceleration;		// ���x�̕ω���
		float angulVelocity;	// �p�x�̕ω���
		float speed;			// �X�s�[�h
		int damage;				// �_���[�W

		bool firing;
		bool bullet_move;
		int move;

		//B_Vector B_pos;			// �e�̓����\����
public:
	


	void Bullet_Firing();
	Bullet();
	void Update(float l_x,float l_y);
	void Draw();
	int GetDamage();

};

