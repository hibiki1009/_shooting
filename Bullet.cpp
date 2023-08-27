#include "Bullet.h"
#include"PAD_INPUT.h"
#include"common.h"
#define _USE_MATH_DEFINES
#include<math.h>


Bullet::Bullet(float l_x, float l_y,bool _Enemyshoot,float _Radian)
{
	firing = FALSE;
	E_shoot = _Enemyshoot;
	// �X�|�[���������̂ݍ��킹��΂�������R���X�g���N�^��OK
	damage = 1;
	Radian = _Radian;
	// �^�[�Q�b�g�̍��W���Aime�̍��W���傫���Ȃ�
	// �^�[�Q�b�g�̍��W
	location.x = l_x;//�����蔻��
	location.y = l_y;
	move = location.y;
	moveX = 10;
	moveY = 10;
	radius = 5;
	WaitTime = 0;
	speed = 10;
	// �G�C���̍��W���擾
}

Bullet::~Bullet()
{
}

float Bullet::inputX() {
	return round(((float)PAD_INPUT::GetPadThumbRX() / 32767) * 100) / 100;
}

float Bullet::inputY() {
	return round(((float)PAD_INPUT::GetPadThumbRY() / 32767) * 100) / 100;
}

void Bullet::Update()
{

	if (E_shoot == false) {
		Distance_Line_Segment();
	}
	// �G�̒e�N��
	if (E_shoot == true) {
		Distance_Line_Segment();
	}
}

void Bullet::Draw()
{
	// �e
	/*DrawFormatString(100, 100,0x000000,"%f", getRadian());*/
	// �v���C���[����ݒ�
	/*DrawCircle(location.x + 5, location.y + 5, radius, 0xcccccc, TRUE);*/
	DrawCircle(location.x, location.y, radius, 0xff0000, TRUE);
}

int Bullet::GetDamage()
{
	return damage;
}

float Bullet::Distance_Line_Segment()
{
	
		float radian = Radian;
		location.x += cos(radian) * speed;
		location.y += sin(radian) * speed;
	/*else {
		++ WaitTime;
		location.x += cos(WaitTime) * speed;
		location.y += sin(WaitTime) * speed;
		if (WaitTime == 360) {
			WaitTime = 0;
	}*/
	
	return 0.0f;
}

