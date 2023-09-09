#include "Player.h"
#include"common.h"
#include<math.h>
// ����
//�@�v���C���[���ŏƏ�������Ď����Ă���
// �W���̍��W�̓R���X�g���N�^�ň�񂾂����
Player::Player()
{
	Waittime = 0;
	score = 0;
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT - 100;

	aim_x = SCREEN_WIDTH / 2;
	aim_y = SCREEN_HEIGHT - 100;

	radius = 5;
	bullet_speed = 10;
	Speed = 5;
	aim_Speed = 100;
	hp = 2000;
}

Player::~Player()
{

}
void Player::Update()
{
	PlayerMove();
	Aiming();

}

// �v���C���[�ƃG�C���|�C���g�̊p�x���擾
float Player::getRadian()
{
	float w = aim_x - location.x;
	float h = aim_y - location.y;

	// h�`w�͈̔͂̃��W�A���l���o��
	return atan2f(h, w);
}

// ��������Bullet���ɂ���


void Player::Draw()const
{

	// �e
	//DrawCircle(location.x + 5, location.y + 5, 5, 0xcccccc, TRUE);
	DrawCircle(location.x, location.y, 5, 0x000000, TRUE);
	DrawCircle(aim_x, aim_y, 3, 0xff0000, TRUE);
	DrawLine(location.x, location.y,aim_x, aim_y, 0xff0000);
	DrawFormatString(location.x - 20, location.y - 30, 0x000000, "%d", hp);
	
}

 //�R���g���[���̓��͂�Ԃ�
float Player::inputX() {
	return round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100;
}

float Player::inputY() {
	return round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100;
}

float Player::inputRX()
{
	return round(((float)PAD_INPUT::GetPadThumbRX() / 32767) * 100) / 100;
}

float Player::inputRY()
{
	return round(((float)PAD_INPUT::GetPadThumbRY() / 32767) * 100) / 100;
}

void Player::Aiming()
{


	aim_x = location.x + inputRX() * 2000;

	aim_y = location.y + inputRY() * 2000;

}


void Player::PlayerMove()
{
	// �ړ�����
	if (inputX() <= -0.3) {
		location.x += -Speed;
	}
	if (inputX() >= 0.3) {
		location.x += Speed;
	}
	if (inputY() <= -0.3) {
		location.y += -Speed;
	}

	if (inputY() >= 0.3) {
		location.y += Speed;
	}

	// �ړ���������
	if (location.x <= 10)
	{
		location.x = 10;
	}
	if (location.x >= SCREEN_WIDTH - 10)
	{
		location.x = SCREEN_WIDTH - 10;
	}

	if (location.y <= 10)
	{
		location.y = 10;
	}
	if (location.y >= SCREEN_HEIGHT - 10)
	{
		location.y = SCREEN_HEIGHT - 10;
	}
	

}

bool Player::shoot() {
	if (++Waittime % 2 == 0) {

		return true;
	}
	return false;
}

int Player::GetHp() {
	return hp;
}

void Player::PlayerInit()
{
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT - 100;
	hp = 20;
}

float Player::GetAime_x()
{
	return aim_x;
}

float Player::GetAime_y()
{
	return aim_y;
}