#pragma once
#include "SphereCollider.h"

typedef struct Bullet_Vector {
	float x, y;
}B_Vector;

class Bullet:public SphereCollider
{
private:
		float angle;			// 角度
		float acceleration;		// 速度の変化量
		float angulVelocity;	// 角度の変化量
		bool firing;
		bool bullet_move;
		int move;
		
		int damage;
		float speed;				// スピード

		B_Vector B_pos;			// 弾の位置構造体
public:
	


	void Bullet_Firing();

	Bullet();
	void Update();
	void Draw();
	int GetDamage();
};

