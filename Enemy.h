#pragma once
#include"DxLib.h"
#include"CharaBase.h"
class Enemy:public CharaBase
{
private:
	int hp;


public:
	int point;

	void Update() override;
	void Draw()const override;
	int Hit(SphereCollider bullet) override;
};

