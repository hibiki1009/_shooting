#include "GameMain.h"
#include"SphereCollider.h"
#include"PAD_INPUT.h"


GameMain::GameMain()
{
	WaitTime = 0;
	shoot_i = 1;
	player = new Player;
	enemy = new Enemy;
	/*B_spawner = new BulletsSpawner;*/
	// コンストラクタで全て殻にする
	for (int i = 0; i < 1000; i++) {
		bullet[i] = nullptr;
	}
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
	enemy->Update();
	// 球を発射する処理
	/*if (B_spawner->Shoot(&bullet[shoot_i]) == true) {*/
		SpawnBullet();
	/*}*/
	for (int i = 0; i < 1000; i++) {
		//中身があるならUpdate処理する
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
		}
	}

	// 弾丸の位置
	
	HitCheck();

}

void GameMain::Draw() const
{
	player->Draw();
	enemy->Draw();
	for (int i = 0; i < 1000; i++) {
		// 中身があるならDraw処理する
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
}

int GameMain::HitCheck()
{
	enemy->Update();
	//printfDx("  %d  ", enemy->Gethp());
	enemy->SetHit(false);
	for (int i = 1; i < 1000; i++) {
		if (bullet[i] != nullptr) {
			// 中身があるならHit処理する
			if (bullet[i]->HitSphere(player) == true)
			{
				printfDx("Hit");
			}

			enemy->Hit(bullet[i]->GetDamage());
			if (bullet[i]->HitSphere(enemy) == true)
			{
				enemy->SetHit(true);
			/*	printfDx("HitEnemy");*/
			}
		}
	}
	return 0;
}

void GameMain::SpawnBullet()
{

	if (shoot_i == 1000) {
		shoot_i = 1;
	}

	// Aが押されている間入る
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A)) {
		
	// 中身がないなら新しいplayer座標をもったBulletクラスを代入する
			if (bullet[shoot_i] == nullptr) {
				bullet[shoot_i] = new Bullet(player->GetLocation().x, player->GetLocation().y);
					shoot_i = shoot_i + 1;
				
				/*printfDx("  %d  ", shoot_i);*/
			}
			else {// *memo*   nullでない　かつ　y==0ならshoot_i=nullをする

			}
			if (shoot_i <= 400) {
				for (int i = 500; i < 1000; i++) {
					if (bullet[i] != nullptr) {
						bullet[i] = nullptr;
					}
				}
			}

			if (shoot_i > 600) {
				for (int j = 0; j <= 500; j++) {
					if (bullet[j] != nullptr) {
						bullet[j] = nullptr;
					}
				}
			}
			
	}
}
