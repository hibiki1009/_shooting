#pragma once
#include"GameMain.h"

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
	int Shoot(GameMain* spawn);

};

