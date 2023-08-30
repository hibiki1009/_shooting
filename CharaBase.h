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
	virtual void Hit(int _damage);		// �_���[�W���� �_���[�W���󂯎��A�c��Hp���v�Z���ĕԂ�
										// �����Œe�̃_���[�W���Ƃ��Ă���

	virtual float GetBullet_speed();
};

