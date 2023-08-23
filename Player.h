#pragma once
#include"SphereCollider.h"
#include"CharaBase.h"
#include"PAD_INPUT.h"
#include <math.h>
#include"Bullet.h"



class Player:public CharaBase
{
private:
	int HitBullet;		// �e�X�g�p
	int score;
	int hp;
	float Speed;			// �v���C���[�X�s�[�h
	float aim_Speed;		// �G�C���̊��x
	float Pr;
	float start;

	float aim_x;
	float aim_y;
	int aim_img;

public:
	/*Bullet* bullet;*/
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

	float inputRX();
	float inputRY();

	void Aiming();
	// Player�̈ړ��Ɋւ��鏈��
	void PlayerMove();
	/*void Bullet_Move();*/

	float GetAime_x();
	float GetAime_y();

	float getRadian();
	int GetHp();
	void Hit(int _damage)override;
};

