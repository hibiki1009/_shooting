#include "GameMain.h"
#include"SphereCollider.h"
#include"PAD_INPUT.h"


GameMain::GameMain()
{
	Score = 0;
	WaitTime = 0;
	shoot_i = 1;
	Eshoot_i = 1;

	player = new Player;
	enemy = new Enemy(0);
	gimmick = new GIMMICK;
	ui = new UI;
	/*B_spawner = new BulletsSpawner;*/
	// コンストラクタで全て殻にする
	for (int i = 0; i < Bullet_Num; i++) {
		bullet[i] = nullptr;
	}

	for (int i = 0; i < Bullet_Num; i++) {
		Ebullet[i] = nullptr;
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
	ui->SetScore(Score);
	player->Update();
	if (enemy != nullptr) {
		enemy->Update();
		enemy->Enemy_move(player->GetLocation().x, player->GetLocation().y);


		if (enemy->Gethp() < 0) {
			Score = Score + enemy->GetPoint();
			enemy = nullptr;
		}
	}
	// 球を発射する処理
	/*if (B_spawner->Shoot(&bullet[shoot_i]) == true) {*/
		SpawnBullet();
	/*}*/
	for (int i = 0; i < Bullet_Num; i++) {
		//中身があるならUpdate処理する
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
		}
	}
	for (int i = 0; i < Bullet_Num; i++) {
		//中身があるならUpdate処理する
		if (Ebullet[i] != nullptr) {
			Ebullet[i]->Update();
		}
	}

	// 弾丸の位置
	
	HitCheck();

}

void GameMain::Draw() const
{
	ui->Draw();
	if (player != nullptr) {
		player->Draw();
	}
	if (enemy != nullptr) {
		enemy->Draw();
	}
	for (int i = 0; i < Bullet_Num; i++) {
		// 中身があるならDraw処理する
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}

	for (int i = 0; i < Bullet_Num; i++) {
		// 中身があるならDraw処理する
		if (Ebullet[i] != nullptr) {
			Ebullet[i]->Draw();
		}
	}
}

int GameMain::HitCheck()
{
	//printfDx("  %d  ", enemy->Gethp());
	if (enemy != nullptr) {
	
		for (int i = 1; i < Bullet_Num; i++) {
			if (bullet[i] != nullptr) {
				// 中身があるならHit処理する
				if (bullet[i]->HitSphere(player) == true)
				{
					printfDx("Hit");
				}

				if (bullet[i]->HitSphere(enemy) == true)
				{
					enemy->Hit(bullet[i]->GetDamage());
						bullet[i] = nullptr;
					/*	printfDx("HitEnemy");*/
				}
			}
		}
	}
	return 0;
}

void GameMain::SpawnBullet()
{

	
	if (shoot_i == Bullet_Num) {
		shoot_i = 1;
	}
	if (Eshoot_i == Bullet_Num) {
		Eshoot_i = 1;
	}

	// Aが押されている間入る
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A)) {
		
	// 中身がないなら新しいplayer座標をもったBulletクラスを代入する
			if (bullet[shoot_i] == nullptr) {
				bullet[shoot_i] = new Bullet(player->GetLocation().x, player->GetLocation().y,false);
					shoot_i = shoot_i + 1;
			}

			// 1～300をnullにする
			if (shoot_i > 600) {
				for (int i = 1; i <= 300; i++)
				{
					if (bullet[i] != nullptr) {
						bullet[i] = nullptr;
					}
				}
			}

			// 301～600をnullにする
			if (shoot_i <= 300) {
				for (int i = 301; i <= 600; i++)
				{
					if (bullet[i] != nullptr) {
						bullet[i] = nullptr;
					}
				}
			}
			// 601～900をnullにする
			if (shoot_i > 300 && 600 >= shoot_i) {
				for (int i = 601; i <= 900; i++)
				{
					if (bullet[i] != nullptr) {
						bullet[i] = nullptr;
					}
				}
			}
			
	}
	// ここからエネミー
	if(enemy!=nullptr){
		if (enemy->shoot() == true) {
			if (Ebullet[Eshoot_i] == nullptr) {
				Ebullet[Eshoot_i] = new Bullet(enemy->GetLocation().x, enemy->GetLocation().y, true);
				Eshoot_i = Eshoot_i + 1;
			}

			// 301～600をnullにする
			if (Eshoot_i <= 300) {
				for (int i = 301; i <= 600; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
			// 601～900をnullにする
			if (Eshoot_i > 300 && 600 >= Eshoot_i) {
				for (int i = 601; i <= 900; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
			// 1～300をnullにする
			if (Eshoot_i > 600) {
				for (int i = 1; i <= 300; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
		}
	}
}
