#pragma once
#include"DxLib.h"
#include"CharaBase.h"
#include"SphereCollider.h"
#include <math.h>
class Enemy:public CharaBase
{
private:
	int E_num;
	int point;
	bool hit;
	int color;
	int WaitTime;

	int Type;
	float Set_PlocationX;
	float Set_PlocationY;

public:
	Enemy(float _x, float _y,float _r,float _speed,float b_speed,int score,int hp,int E_num);
	~Enemy();

	// 一定時間経過ごとにプレイヤーの座標に向かおうとする(x軸)
	void Enemy_move(float _x,float _y);

	int Gethp();
	int GetPoint();

	bool shoot();
	void Update() override;
	void Draw()const override;
	float getRadian();
	void SetPlayerlocation(float _x,float  _y);
	void Sethp(int damage);
};

