#include "Enemy.h"
#include"common.h"

Enemy::Enemy(int _SpownX) {

	point = 100;
	WaitTime = 0;
	forming = false;
	hp = 1000;
	location.x = GetRand(SCREEN_WIDTH);
	location.y = -100;
	radius = 15;
	color = 0x000000;
	f_time = 0;
	/*Speed = 5;
	start = 1.15f;
	BulletFlg = 1;*/
}
Enemy::~Enemy()
{
}
void Enemy::Hit(int _damage)
{
			color = 0xff0000;
			hp = hp - _damage;
			color = 0x000000;
}

void Enemy::Update()
{
	if (location.y < 100) {
		location.y++;
	}
	if (GetRand(10) <= 5) {
		forming = true;
	}
	else {
		forming = false;
	}
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y, radius, color, TRUE);
}



void Enemy::Enemy_move(float _x, float _y) {
	//if (++WaitTime %3==0) {
		if (_x < location.x) {
			location.x = location.x - 1;
		}
		else {
			location.x = location.x + 1;
		}
		if (_x == location.x) {
			location.x = location.x;
		}
	/*}*/
}

bool Enemy::shoot() {
	if (++WaitTime % 15 == 0) {
		return true;
	}
	return false;
}


int Enemy::Gethp() {
	return hp;
}
int Enemy::GetPoint() {
	return point;
}
