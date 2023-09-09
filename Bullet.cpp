#include "Bullet.h"
#include"PAD_INPUT.h"
#include"common.h"
#define _USE_MATH_DEFINES
#include<math.h>


Bullet::Bullet(float l_x, float l_y,bool _Enemyshoot,float _Radian,float b_speed)
{
	firing = FALSE;
	E_shoot = _Enemyshoot;
	// スポーンした時のみ合わせればいいからコンストラクタでOK
	damage = 5;
	Radian = _Radian;
	// ターゲットの座標よりAimeの座標が大きいなら
	// ターゲットの座標
	location.x = l_x;
	location.y = l_y;
	move = location.y;
	moveX = 10;
	moveY = 10;
	radius = 5;
	WaitTime = 0;
	Bullet_speed = b_speed;
	// エイムの座標を取得
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
	if (location.x > -radius * 2 && location.x < SCREEN_WIDTH + radius * 2) {
		if (location.y > -radius * 2 && location.y < SCREEN_HEIGHT + radius * 2) {
			if (E_shoot == false) {
				color = 0xdd0000;
				Distance_Line_Segment();
			}
			// 敵の弾起動
			if (E_shoot == true) {
				color = 0xff0000;
				Distance_Line_Segment();
			}
		}
	}
}

void Bullet::Draw()
{
	// 影
	/*DrawFormatString(100, 100,0x000000,"%f", getRadian());*/
	// プレイヤー操作設定
	/*DrawCircle(location.x + 5, location.y + 5, radius, 0xcccccc, TRUE);*/
	DrawCircle(location.x, location.y, radius, color, TRUE);
}

int Bullet::GetDamage()
{
	return damage;
}

float Bullet::Distance_Line_Segment()
{
	
		float radian = Radian;
		location.x += cos(radian) * Bullet_speed;
		location.y += sin(radian) * Bullet_speed;
	/*else {
		++ WaitTime;
		location.x += cos(WaitTime) * speed;
		location.y += sin(WaitTime) * speed;
		if (WaitTime == 360) {
			WaitTime = 0;
	}*/
	
	return 0.0f;
}

float Bullet::GetLocationX()
{
	return location.x;
}

float Bullet::GetLocationY()
{
	return location.y;
}

