#pragma once
#include"GameMain.h"
#include"Bullet.h"
#include "common.h"
#include"SphereCollider.h"


class BulletsSpawner /*:public SphereCollider*/
{
private:
	float speed;
	float angle;
	float acceleration;			// ���x�̕ω���
	float angulVelocity;		// �p�x�̕ω���

public:
	// �����ɃQ�[�����C���V�[���̃|�C���^���󂯎��SpawnBullet�Œe�𐶐�����
	// �e�𔭎˂���	

	/*int Shoot(GameMain* gamemain);*/
};

