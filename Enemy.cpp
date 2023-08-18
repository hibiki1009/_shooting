#include "Enemy.h"
#include"common.h"

Enemy::Enemy(/*float _x, float _y*/) {
	hp = 1000;
	location.x = SCREEN_WIDTH / 2 ;
	location.y = 100;
	radius = 15;
	color = 0xffffff;
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
	if (hit == true) {
			color = 0xff0000;
			hp = hp - _damage;
	}
	else if(hp>0) {
		// ‰¼
		color = 0xffffff;
	}
}

int Enemy::Gethp() {
	return hp;
}
void Enemy::SetHit(bool _hit)
{
	hit = _hit;
}
void Enemy::Update()
{
	if (hp < 0) {
		color = 0x000000;
	}
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y, radius, color, TRUE);
}
