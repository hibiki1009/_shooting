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
	Enemy();
	~Enemy();

	void EnemyDamage();
	void SetHit(bool _hit);
	int point;

	void Update() override;
	void Draw()const override;
	/*int Hit(SphereCollider bullet) override;*/
};

