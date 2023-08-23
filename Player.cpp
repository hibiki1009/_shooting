#include "Player.h"
#include"common.h"
#include<math.h>
// メモ
//　プレイヤー側で照準を作って持っていく
// 標準の座標はコンストラクタで一回だけ取る
Player::Player()
{
	/*bullet = new Bullet;*/
	aim_img = LoadGraph("images/UI/AIme.jpg", TRUE);
	score = 0;
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT - 100;

	aim_x = SCREEN_WIDTH / 2;
	aim_y = SCREEN_HEIGHT - 100;

	radius = 5;

	Speed = 5;
	aim_Speed = 100;
	hp = 50;
}

Player::~Player()
{

}
void Player::Update()
{
	PlayerMove();
	Aiming();

}

void Player::Hit(int _damage)
{
	hp = hp - _damage;
}

// プレイヤーとエイムポイントの角度を取得
float Player::getRadian()
{
	float w = aim_x - location.x;
	float h = aim_y - location.y;

	return atan2f(h, w);
}

// こっちはBullet側にかく


void Player::Draw()const
{

	// 影
	//DrawCircle(location.x + 5, location.y + 5, 5, 0xcccccc, TRUE);
	DrawCircle(location.x, location.y, 5, 0x000000, TRUE);
	DrawCircle(aim_x, aim_y, 3, 0xff0000, TRUE);
	DrawLine(location.x, location.y,aim_x, aim_y, 0xff0000);
	DrawFormatString(location.x - 20, location.y - 30, 0xff0000, "%d", hp);
	
}

 //コントローラの入力を返す
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
	// 移動処理
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

	// 移動制限処理
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
int Player::GetHp() {
	return hp;
}

float Player::GetAime_x()
{
	return aim_x;
}

float Player::GetAime_y()
{
	return aim_y;
}