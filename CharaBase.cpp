#include "CharaBase.h"

void CharaBase::Update()
{
}

void CharaBase::Draw()const
{

}

// ��{�I��HP�������s��
void CharaBase::Hit(int _damage)
{
    hp = hp - _damage;
}
