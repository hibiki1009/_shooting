#pragma once
#include <vector>
#include "AbstractScene.h"
#include"DxLib.h"

#include"Player.h"
#include"Bullet.h"


class GameMain :public AbstractScene {
private:
	int life;				// �c�@
	int* enemy[5];			// �|�C���^�z��
	int* bullets[10];			// �|�C���^�z��

public:

	// �N���X�I�u�W�F�N�g
	Player* player;
	Bullet* bullet;

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

