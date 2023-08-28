#pragma once
#include <vector>
#include "AbstractScene.h"
#include"DxLib.h"
#include"common.h"

#include"Title.h"
#include"Ranking.h"

#include"UI.h"
#include"CharaBase.h"
#include"Player.h"
#include"Enemy.h"
#include"EnemySpawn.h"
#include"Bullet.h"
#include"GIMMICK.h"
#include"BulletsSpawner.h"
#include"NwaySpawner.h"
#include<vector>

class GameMain :public AbstractScene {
private:
	int life;				// �c�@
	int shoot_i;
	int Eshoot_i;
	int E_num;
	int E_numcnt;
	int WaitTime;
	// ���ϐ�
	int Score;
	float gridX;
	float gridY;
	float Gole_distance;// �S�[���܂ł̋���

	int e_spownCnt;
public:

	// �N���X�I�u�W�F�N�g
	Player* player;
	Enemy* enemy[Enemy_Num];
	GIMMICK* gimmick;
	UI* ui;
	Bullet* bullet[Bullet_Num];

	Bullet* Ebullet[Bullet_Num];

	BulletsSpawner* b_spawner;
	EnemySpawn* e_spawn;

	GameMain* gamemain;
	Ranking* ranking;
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
	void SpawnEnemy();

	int GetShoot();
};

