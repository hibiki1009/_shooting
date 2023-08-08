#pragma once
#include "SphereCollider.h"

typedef struct Bullet_Vector {
	float x, y;
}B_Vector;

class Bullet:public SphereCollider
{
private:
		float angle;			// �p�x
		float acceleration;		// ���x�̕ω���
		float angulVelocity;	// �p�x�̕ω���
		bool firing;
		bool bullet_move;
		int move;
		
		int damage;
		float speed;				// �X�s�[�h

		B_Vector B_pos;			// �e�̈ʒu�\����
public:
	


	void Bullet_Firing();

	Bullet();
	void Update();
	void Draw();
	int GetDamage();
};

