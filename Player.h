#pragma once
#include"SphereCollider.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include <math.h>
#include"Bullet.h"

// ����
// �v���C���[���o���b�g�����悤�ɐ݌v���Ȃ���
// �o���邾���֐��̖߂�l���g���ď���

class Player:public CharaBase
{
private:
	int HitBullet;		// �e�X�g�p
	int score;
	float Speed;			// �v���C���[�X�s�[�h
	float Pr;
	float start;



public:
	/*Bullet* bullet;*/
	static int BulletFlg;		// 1�� 2�E 3�� 4��
	//static int Px, Py;	// �v���C���[�̍��W

	int test = 0;
	Player();
	~Player();

	// override�͊֐��̏������㏑�����邱�Ƃ��ł���
	void Update() override;
	void Draw() const override;

	// �R���g���[���̓��͂�Ԃ�
	float inputX();
	float inputY();

	// Player�̈ړ��Ɋւ��鏈��
	void PlayerMove();
	/*void Bullet_Move();*/
};

