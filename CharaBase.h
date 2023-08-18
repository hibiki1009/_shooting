#pragma once
#include"DxLib.h"
#include"SphereCollider.h"

class CharaBase :public SphereCollider
{
public:
	float speed;
	int image;

	virtual void Update();
	virtual void Draw()const;
	virtual void Hit(int _damage);		// ダメージ処理 ダメージを受け取り、残りHpを計算して返す
									// 引数でプレイヤーと敵のHPをとる
};

