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
	// �R���X�g���N�^�őS�Ċk�ɂ���
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
	// ���𔭎˂��鏈��
	/*if (B_spawner->Shoot(&bullet[shoot_i]) == true) {*/
		SpawnBullet();
	/*}*/
	for (int i = 0; i < 1000; i++) {
		//���g������Ȃ�Update��������
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
		}
	}

	// �e�ۂ̈ʒu
	
	HitCheck();

}

void GameMain::Draw() const
{
	player->Draw();
	enemy->Draw();
	for (int i = 0; i < 1000; i++) {
		// ���g������Ȃ�Draw��������
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
			// ���g������Ȃ�Hit��������
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

	// A��������Ă���ԓ���
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A)) {
		
	// ���g���Ȃ��Ȃ�V����player���W��������Bullet�N���X��������
			if (bullet[shoot_i] == nullptr) {
				bullet[shoot_i] = new Bullet(player->GetLocation().x, player->GetLocation().y);
					shoot_i = shoot_i + 1;
				
				/*printfDx("  %d  ", shoot_i);*/
			}
			else {// *memo*   null�łȂ��@���@y==0�Ȃ�shoot_i=null������

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
