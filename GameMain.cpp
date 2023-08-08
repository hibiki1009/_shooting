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
	/*if (bullet->HitSphere(player) == true)
	{
		printfDx("Hit");
	}*/

	if (bullet->HitSphere(player) == true)
	{
		printfDx("Hit");
	}


	bullet->Update();
	bullet->Bullet_Firing();
	player->Update();
}

void GameMain::Draw() const
{
	player->Draw();
	bullet->Draw();
}
