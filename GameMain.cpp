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

	
	player->Update();

	bullet->Update();
	bullet->Bullet_Firing();

	
	/*player->SetLocation(bullet);*/

	// False‚È‚ç

	if (bullet->HitSphere(player) == true)
	{
		printfDx("Hit");
	}

}

void GameMain::Draw() const
{
	player->Draw();
	bullet->Draw();
}
