#pragma once
#include"Bullet.h"
#include "common.h"
#include"SphereCollider.h"

// �N���X�錾
class GameMain;

class BulletsSpawner
{
private:

	float speed;
	float angle;
	float acceleration;			// ���x�̕ω���
	float angulVelocity;		// �p�x�̕ω���

public:
	// �����ɃQ�[�����C���V�[���̃|�C���^���󂯎��SpawnBullet�Œe�𐶐�����
	// �e�𔭎˂���	

	int Shoot(GameMain* gamemain);
};

