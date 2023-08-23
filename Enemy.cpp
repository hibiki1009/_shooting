#include "Enemy.h"
#include"common.h"

Enemy::Enemy(int _SpownX) {

	point = 100;
	WaitTime = 0;
	forming = false;
	hp = 100;
	location.x = GetRand(SCREEN_WIDTH);
	location.y = -100;
	radius = 50;
	color = 0x000000;
	f_time = 0;
	
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
	if (location.y < 130) {
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
	// ‰e
	clsDx();
	DrawFormatString(location.x-20, location.y - 100,0xff0000,"%d",hp);
	//DrawCircle(location.x + 5, location.y + 5, radius, 0xcccccc, TRUE);
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

}
void Enemy::SetPlayerlocation(float _x,float _y) {
	Set_PlocationX = _x;
	Set_PlocationY = _y;
}

float Enemy::getRadian()
{
	float w = Set_PlocationX - location.x;
	float h = Set_PlocationY - location.y;

	return atan2f(h, w);
}

bool Enemy::shoot() {
	if (++WaitTime % 11 == 0) {
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
