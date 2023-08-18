#pragma once
#include"DxLib.h"
#include"CharaBase.h"
#include"SphereCollider.h"
class Enemy:public CharaBase
{
private:
	int hp;
	bool hit;
	int color;
	int f_time;
public:
	Enemy(/*float _x,float _y*/);
	~Enemy();

	void Hit(int _damage)override;
	void SetHit(bool _hit);
	int Gethp();

	void Update() override;
	void Draw()const override;
	/*int Hit(SphereCollider bullet) override;*/
};

