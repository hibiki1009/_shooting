#include "CharaBase.h"

void CharaBase::Update()
{
}

void CharaBase::Draw()const
{

}

// Šî–{“I‚ÈHPˆ—‚ğs‚¤
void CharaBase::Hit(int _damage)
{
    hp = hp - _damage;
}

float CharaBase::GetBullet_speed()
{
    return bullet_speed;
}
