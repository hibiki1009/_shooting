#include "Bullet.h"
#include"PAD_INPUT.h"
#include"common.h"


Bullet::Bullet(float l_x, float l_y,bool _Enemyshoot)
{
	firing = FALSE;
	E_shoot = _Enemyshoot;
	// スポーンした時のみ合わせればいいからコンストラクタでOK
	damage = 5;
	location.x = l_x;//当たり判定
	location.y = l_y-10;
	move = location.y;
	radius = 5;
}

void Bullet::Bullet_Firing()
{
	
}

void Bullet::Update()
{
	if (E_shoot == false) {
		move = move - 10;
		location.y = move;
	}
	if (E_shoot == true) {
		move = move + 10;
		location.y = move;
	}
}

void Bullet::Draw()
{
	DrawCircle(location.x, location.y, radius, 0xff0000, TRUE);
}

int Bullet::GetDamage()
{
	return damage;
}

//Location Bullet::SetLocation(SphereCollider* spherecollider)
//{
//	return location = spherecollider->GetLocation();
//}

