#include "Enemy.h"
#include"common.h"

Enemy::Enemy() {
	location.x = SCREEN_WIDTH / 2;
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
void Enemy::EnemyDamage()
{
	if (hit == true) {
			color = 0xff0000;
	}
	else {
		color = 0xffffff;
	}
}
void Enemy::SetHit(bool _hit)
{
	hit = _hit;
}
void Enemy::Update()
{
	
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y, radius, color, TRUE);
}
