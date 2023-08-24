#include "GameMain.h"
#include"SphereCollider.h"
#include"PAD_INPUT.h"


GameMain::GameMain()
{
	Gole_distance = 1000;
	Score = 0;
	life = 3;

	WaitTime = 0;
	E_num = 1;
	shoot_i = 1;
	Eshoot_i = 1;

	gridX = 80;
	gridY = 80;

	player = new Player;
	gimmick = new GIMMICK;
	ui = new UI;
	
	for (int i = 0; i < Enemy_Num; i++) {
		enemy[i] = nullptr;
	}

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
	Gole_distance = Gole_distance - 0.08f;
	Game();
	if (life < 1) {
		return new Title;
	}
	return this;
}

void GameMain::Game()
{
	
	
	player->Update();
	
	if (player->GetHp() < 0) {
		if (life != 0) {
			life = life - 1;
			player = new Player;
		}
	}
	SpawnEnemy();

	for (int i = 0; i < Enemy_Num; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();

			// エネミーの移動
			enemy[i]->Enemy_move(player->GetLocation().x, player->GetLocation().y);
			enemy[i]->SetPlayerlocation(player->GetLocation().x, player->GetLocation().y);
			// エネミーのHPを取得、0ならスコア加算
			if (enemy[i]->Gethp() < 0) {
				Score = Score + enemy[i]->GetPoint();
				enemy[i] = nullptr;
			}
		}
	}

		SpawnBullet();
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

	// 弾丸の判定処理
	HitCheck();

	// UIセット関数
	ui->SetScore(Score);
	ui->SetLife(life);
	ui->SetHp(player->GetHp());
	ui->SetP_location(player->GetLocation().x, player->GetLocation().y);
}

void GameMain::Draw() const
{
	// 背景グリッド線
	for (int i = 0; i <= 16; i++) {
		DrawLine(gridX * i, 0, gridX * i, SCREEN_HEIGHT, 0xcccccc, TRUE);
		DrawLine(0, gridY * i, SCREEN_WIDTH, gridY * i, 0xcccccc, TRUE);
	}

	// 仮
	DrawFormatString(0, 100, 0x000000, "ノコリ:%fTB", Gole_distance);
	
	ui->Draw();
	if (player != nullptr) {
		player->Draw();
	}
	// nullじゃないエネミーのみDrawする
	for (int i = 0; i < Enemy_Num; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
		}
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

	// プレイヤーの処理
	for (int i = 0; i < Bullet_Num; i++) {
				
		if (Ebullet[i] != nullptr) {
			// 中身があるならHit処理する
			if (Ebullet[i]->HitSphere(player) == true)
			{
				player->Hit(Ebullet[i]->GetDamage());
				Ebullet[i] = nullptr;
			}
		}

		// エネミーの処理
		for (int j = 0; j < Enemy_Num;j++) {
			// エネミーがnullじゃないなら入る
			if (enemy[j] != nullptr) {
				for (int i = 1; i < Bullet_Num; i++) {
					if (bullet[i] != nullptr) {
						if (bullet[i]->HitSphere(enemy[j]) == true)
						{
							enemy[j]->Hit(bullet[i]->GetDamage());
								bullet[i] = nullptr;
						}
					}
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

	// RBが押されている間入る
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_RIGHT_SHOULDER)) {

		// 中身がないなら新しいplayer座標をもったBulletクラスを代入する
		if (bullet[shoot_i] == nullptr) {

			bullet[shoot_i] = new Bullet(player->GetLocation().x, player->GetLocation().y, false, player->getRadian());
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
	for (int j = 0; j < Enemy_Num; j++){
	// エネミーがnullでない
	if(enemy[j] != nullptr) {
		if (enemy[j]->shoot() == true) {
			if (Ebullet[Eshoot_i] == nullptr) {
				Ebullet[Eshoot_i] = new Bullet(enemy[j]->GetLocation().x, enemy[j]->GetLocation().y, true,enemy[j]->getRadian());
				Eshoot_i = Eshoot_i + 1;
			}
		}

			// 301～600をnullにする
			if (Eshoot_i <= 30) {
				for (int i = 31; i <= 60; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
			// 601～900をnullにする
			if (Eshoot_i > 30 && 60 >= Eshoot_i) {
				for (int i = 61; i <= 90; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
			// 1～300をnullにする
			if (Eshoot_i > 60) {
				for (int i = 1; i <= 30; i++)
				{
					if (Ebullet[i] != nullptr) {
						Ebullet[i] = nullptr;
					}
				}
			}
		}
	}
}

void GameMain::SpawnEnemy()
{
		if (enemy[E_num] == nullptr) {
			enemy[E_num] = new Enemy(SCREEN_WIDTH / 2);
				/*E_num = E_num + 1;*/
			/*E_num = E_num + 1;
			if (E_num > 2) {
				E_num = 0;
			}*/
		}
	}

