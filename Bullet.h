#pragma once
#include "SphereCollider.h"
#include<vector>

//typedef struct Bullet_Vector {
//	float x, y;
//}B_Vector;

class Bullet:public SphereCollider
{
private:
		float angle;			// 角度
		float acceleration;		// 速度の変化量
		float angulVelocity;	// 角度の変化量
		float speed;			// スピード
		int damage;				// ダメージ

		bool firing;
		bool bullet_move;
		int move;

		//B_Vector B_pos;			// 弾の動き構造体
public:
	


	void Bullet_Firing();
	Bullet();
	void Update(float l_x,float l_y);
	void Draw();
	int GetDamage();

};

