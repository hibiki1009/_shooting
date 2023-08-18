#include "Bullet.h"
#include"PAD_INPUT.h"
#include"common.h"


Bullet::Bullet(float l_x, float l_y)
{
	firing = FALSE;

	// �X�|�[���������̂ݍ��킹��΂�������R���X�g���N�^��OK
	damage = 100;
	location.x = l_x;//�����蔻��
	location.y = l_y-10;
	move = location.y;
	radius = 5;
}

void Bullet::Bullet_Firing()
{
	
}

void Bullet::Update()
{
	/*printfDx("  %d  ", move);*/
	move = move-10;
	location.y = move;
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

