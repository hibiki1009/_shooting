#pragma once
#include"DxLib.h"
#include"CharaBase.h"
#include"SphereCollider.h"
class Enemy:public CharaBase
{
private:
	int point;
	int hp;
	bool hit;
	int color;
	int f_time;
	int move;
	bool forming;
	int WaitTime;
public:
	Enemy(int _SpownX);
	~Enemy();

	// 一定時間経過ごとにプレイヤーの座標に向かおうとする(x軸)
	void Enemy_move(float _x,float _y);

	void Hit(int _damage)override;
	int Gethp();
	int GetPoint();
	bool shoot();
	void Update() override;
	void Draw()const override;
};

