#pragma once
#include <vector>
#include "AbstractScene.h"
#include"DxLib.h"
#include"common.h"

#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"BulletsSpawner.h"
#include<vector>

class GameMain :public AbstractScene {
private:
	int life;				// �c�@
	int shoot_i;
	int WaitTime;
public:

	// �N���X�I�u�W�F�N�g
	Player* player;
	Enemy* enemy;
	// Bullet��z��
	Bullet *bullet[1000];
	/*BulletsSpawner *B_spawner;*/

	void Game();
	// �R���X�g���N�^
	GameMain();

	// �f�X�g���N�^
	virtual ~GameMain();

	// �`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	// �`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;

	int HitCheck();			// �e / �v���C���[ / �G�̓����蔻��̃`�F�b�N���s��

	void SpawnBullet();			// �e�̔z��ɐV�����f�[�^���쐬����

};

