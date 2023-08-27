#pragma once
#include "common.h"

struct E_NUM
{
	float location_x;
	float location_y;
	float radius;
	float speed;
	float bullet_speed;
	int score;
	int hp;
	int time;
};

class EnemySpawn
{
private:

	static E_NUM data[63];			// �G�̐��̍ő吔
	static int row;						// csv�t�@�C���̗�̐�(�ǂݍ��܂��G�̗�)
public:
	EnemySpawn();						// �R���X�g���N�^
	~EnemySpawn();						// �f�X�g���N�^
	static E_NUM LoadEnemy(int i);	// �G���̓ǂݍ���
	static int GetMaxEnemy();			// �ǂݍ��܂ꂽ�G�̗ʂ̎擾
};