#include "Bullet.h"
#include"PAD_INPUT.h"
#include"common.h"


Bullet::Bullet()
{
	player = new Player;
	firing = FALSE;
	bullet_move = FALSE;

	location.x = 100;//当たり判定
	location.y = 300;
	radius = 10;
}

void Bullet::Bullet_Firing()
{
	
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A))
	{
		firing = TRUE;
	}
	else {
		firing = FALSE;
	}

	if (firing == TRUE) {
		bullet_move = TRUE;
	}

	
		test1 = Player::BulletFlg;
		switch (test1)
		{
		case 1:
			if (bullet_move == TRUE) {
				location.y = location.y - move;
			}
			break;
		case 2:
			if (bullet_move == TRUE) {
				location.x = location.x + move;
			}
			break;
		case 3:
			if (bullet_move == TRUE) {
				location.y = location.y + move;
			}
			break;
		case 4:
			if (bullet_move == TRUE) {
				location.x = location.x - move;
			}
			break;
		}
	//	テスト用

	if (location.x <= 10)
	{
		bullet_move = FALSE;
	}
	if (location.x >= SCREEN_WIDTH - 10)
	{
		bullet_move = FALSE;
	}

	if (location.y <= 10)
	{
		bullet_move = FALSE;
	}
	if (location.y >= SCREEN_HEIGHT - 10)
	{
		bullet_move = FALSE;
	}
	if (bullet_move == FALSE)
	{
		location = player->GetLocation();
	}
}

void Bullet::Update()
{
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
	DrawCircle(location.x, location.y, 10, 0xff0000, TRUE);
}

int Bullet::GetDamage()
{
	return 0;
}

//int Bullet::Hit(SphereCollider bullet)
//{
//		// チェックの結果を見ているだけ
//		int HitEnemy = CheckCollision(bullet);
//		if (HitEnemy == TRUE) {
//			printfDx("Hit");
//		}
//		return 0;
//}
//
//int Bullet::PlayerHit(Player player)
//{
//	int Hit = Bullet::CheckCollision(player);
//
//	if (Hit == TRUE) {
//		printfDx("Hit");
//	}
//
//	return 0;
//}