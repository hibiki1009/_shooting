#include "Enemy.h"
#include"common.h"

Enemy::Enemy(float _x, float _y, float _r, float _speed, float b_speed, int score,int _hp,int _E_num) {

	point = score;
	WaitTime = 0;
	E_num = _E_num;
	hp = _hp;
	speed = _speed;
	location.x = _x;
	location.y = _y;
	radius = _r;
	color = 0x000000;
	
}
Enemy::~Enemy()
{
}
void Enemy::Update()
{
	printfDx("%d", E_num);
	// 敵がボスだったら
	if (E_num == 5) {
		if (location.y < SCREEN_HEIGHT/2) {
			location.y++;
		}
	}else{
		
	}
	// ボス以外なら
	if (location.y < SCREEN_HEIGHT+100 && E_num != 5) {
		location.y++;
	}
}

void Enemy::Draw()const
{
	// 影
	clsDx();
	DrawFormatString(location.x-20, location.y - 100,0x000000,"%d",hp);
	//DrawCircle(location.x + 5, location.y + 5, radius, 0xcccccc, TRUE);
	DrawCircle(location.x, location.y, radius, color, TRUE);
}



void Enemy::Enemy_move(float _x, float _y) {
	//if (++WaitTime %3==0) {
		/*if (_x < location.x) {
			location.x = location.x - 1;
		}
		else {
			location.x = location.x + 1;
		}
		if (_x == location.x) {
			location.x = location.x;
		}*/

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
