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
	// �R���X�g���N�^�őS�Ċk�ɂ���
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
	// ���𔭎˂��鏈��
	/*if (B_spawner->Shoot(&bullet[shoot_i]) == true) {*/
		SpawnBullet();
	/*}*/
	for (int i = 0; i < Bullet_Num; i++) {
		//���g������Ȃ�Update��������
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
		}
	}
	for (int i = 0; i < Bullet_Num; i++) {
		//���g������Ȃ�Update��������
		if (Ebullet[i] != nullptr) {
			Ebullet[i]->Update();
		}
	}

	// �e�ۂ̈ʒu
	
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
		// ���g������Ȃ�Draw��������
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}

	for (int i = 0; i < Bullet_Num; i++) {
		// ���g������Ȃ�Draw��������
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
				// ���g������Ȃ�Hit��������
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

	// A��������Ă���ԓ���
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A)) {
		
	// ���g���Ȃ��Ȃ�V����player���W��������Bullet�N���X��������
			if (bullet[shoot_i] == nullptr) {
				bullet[shoot_i] = new Bullet(player->GetLocation().x, player->GetLocation().y,false);
					shoot_i = shoot_i + 1;
			}

			// 1�`300��null�ɂ���
			if (shoot_i > 600) {
				for (int i = 1; i <= 300; i++)
				{
					if (bullet[i] != nullptr) {
						bullet[i] = nullptr;
					}
				}
			}

			// 301�`600��null�ɂ���
			if (shoot_i <= 300) {
				for (int i = 301; i <= 600; i++)
				{
					if (bullet[i] != nullptr) {
						bullet[i] = nullptr;
					}
				}
			}
			// 601�`900��null�ɂ���
			if (shoot_i > 300 && 600 >= shoot_i) {
				for (int i = 601; i <= 900; i++)
				{
					if (bullet[i] != nullptr) {
						bullet[i] = nullptr;
					}
				}
			}
			
	}
	// ��������G�l�~�[
	if(enemy!=nullptr){
		if (enemy->shoot() == true) {
			if (Ebullet[Eshoot_i] == nullptr) {
				Ebullet[Eshoot_i] = new Bullet(enemy->GetLocation().x, enemy->GetLocation().y, true);
				Eshoot_i = Eshoot_i + 1;
			}

			// 301�`600��null�ɂ���
			if (Eshoot_i <= 300) {
				for (int i = 301; i <= 600; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
			// 601�`900��null�ɂ���
			if (Eshoot_i > 300 && 600 >= Eshoot_i) {
				for (int i = 601; i <= 900; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
			// 1�`300��null�ɂ���
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
