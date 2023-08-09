#include "GameMain.h"
#include"SphereCollider.h"



GameMain::GameMain()
{
	player = new Player;
	bullet = new Bullet;
}

GameMain::~GameMain()
{
	
}

AbstractScene* GameMain::Update()
{
	Game();
	return this;
}

void GameMain::Game()
{
	player->Update();
	player->Bullet_Move();

	/*if (bullet->HitSphere(player) == true)
	{
		printfDx("Hit");
	}*/

}

void GameMain::Draw() const
{
	player->Draw();
	bullet->Draw();
}

int GameMain::HitCheck()
{
	return 0;
}

void GameMain::SpawnBullet()
{

}
