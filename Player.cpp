#include "Player.h"
#include"common.h"

int Player::BulletFlg;

Player::Player()
{
	score = 0;
	location.x = SCREEN_WIDTH / 2;
	location.y = SCREEN_HEIGHT - 100;
	radius = 5;

	Speed = 5;
	start = 1.15f;
	BulletFlg = 1;
}

Player::~Player()
{
}
void Player::Update()
{
	// 傾きを取得、左方向に移動

	if (inputX() <= -0.3) {
		location.x -= Speed;
		BulletFlg = 4;
	}
	// 傾きを取得、右方向に移動
	if (inputX() >= 0.3) {
		location.x += Speed;
		BulletFlg = 2;
	}
	if (inputY() <= -0.3) {
		location.y -= Speed;
		BulletFlg = 1;
	}

	if (inputY() >= 0.3) {
		start = 1.15f;
		location.y += Speed;
		BulletFlg = 3;
	}

	if (location.x <= 10)
	{
		location.x = 10;
	}
	if (location.x >= SCREEN_WIDTH-10)
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

void Player::Draw()const
{
	// テスト用
	DrawCircle(location.x, location.y, 5, 0xffffff, TRUE);
	//if (HitBullet == TRUE)
	//{
	//	// テスト用
	//	printfDx("当っています");
	//}
}


 //コントローラの入力を返す
float Player::inputX() {
	return round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100;
}

float Player::inputY() {
	return round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100;
}