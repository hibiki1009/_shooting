#include "CharaBase.h"

void CharaBase::Update()
{
}

void CharaBase::Draw()const
{

}

// 基本的なHP処理を行う
void CharaBase::Hit(int _damage)
{
    hp = hp - _damage;
}

float CharaBase::GetBullet_speed()
{
    return bullet_speed;
}
