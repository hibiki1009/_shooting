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
	virtual void Hit(int _damage);		// �_���[�W���� �_���[�W���󂯎��A�c��Hp���v�Z���ĕԂ�
									// �����Ńv���C���[�ƓG��HP���Ƃ�
};

