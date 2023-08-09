#include "Bullet.h"
#include"PAD_INPUT.h"
#include"common.h"


Bullet::Bullet()
{
	firing = FALSE;
	bullet_move = FALSE;

	location.x = 100;//当たり判定
	location.y = 300;
	radius = 5;
}

void Bullet::Bullet_Firing()
{
	
}

void Bullet::Update(float l_x, float l_y)
{
	/*location.x = l_x;
	location.y = l_y;*/

	/*printfDx("%d", bullet_move);*/
	static int WeitTime = 0;
	WeitTime++;
	if (WeitTime % 5 == 0 && bullet_move == TRUE)
	{
		move = move+10;
	}
	if (bullet_move == FALSE) {
		move = 0;
	}
}

void Bullet::Draw()
{
	// テスト用
	DrawCircle(location.x, location.y, radius, 0xff0000, TRUE);
}

int Bullet::GetDamage()
{
	return 0;
}

