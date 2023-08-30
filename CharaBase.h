#pragma once
#include"DxLib.h"
#include"SphereCollider.h"

class CharaBase :public SphereCollider
{
protected:
	float speed;
	int image;
	int hp;
	float bullet_speed;

public:
	virtual void Update();
	virtual void Draw()const;
	virtual void Hit(int _damage);		// ダメージ処理 ダメージを受け取り、残りHpを計算して返す
										// 引数で弾のダメージをとっている

	virtual float GetBullet_speed();
};

