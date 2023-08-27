#include "GameMain.h"
#include"SphereCollider.h"
#include"PAD_INPUT.h"
#include"EnemySpawn.h"


GameMain::GameMain()
{
	Gole_distance = 1000;
	Score = 0;
	life = 3;

	WaitTime = 0;
	E_num = 1;
	e_spownCnt = 0;
	shoot_i = 1;
	Eshoot_i = 1;
	E_numcnt = 1;

	gridX = 80;
	gridY = 80;

	player = new Player;
	gimmick = nullptr;
	ui = new UI;
	b_spawner = new BulletsSpawner;
	e_spawn = new EnemySpawn;

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

	if (gimmick != nullptr) {
		// 追尾ギミックようにプレイヤーの座標取得
		gimmick->Set_P_Location(player->GetLocation().x, player->GetLocation().y);
		// ギミックようにプレイヤーのHpを取得
		gimmick->Set_P_Hp(player->GetHp());
		// ギミックのアップデート処理
		gimmick->KillCircle_Update();
	}

	
	// プレイヤーのHP処理
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

		/*b_spawner->Shoot(gamemain);*/

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
	if (gimmick != nullptr) {
		// キルサークルギミックのDraw
		gimmick->KillCircle_Draw();
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
	// ギミックとプレイヤーの判定処理
	if (gimmick != nullptr) {
		if (gimmick->Get_CircleKill() == true && gimmick->HitSphere(player)) {
			player->Hit(gimmick->Get_Damage());
		}
		// ギミックの時間が0なら消す
		if (gimmick->Get_Circle_time() < 0) {
			gimmick = nullptr;
		}
	}

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
	E_num = 5;
		if (enemy[E_num] == nullptr) {
				// エネミーの出現時間に到達したら
				if (++e_spownCnt > e_spawn->LoadEnemy(E_num).time * FRAMERATE) {
					//出現したエネミーの情報を全て送信
					enemy[E_num] = new Enemy(e_spawn->LoadEnemy(E_num).location_x, e_spawn->LoadEnemy(E_num).location_y, e_spawn->LoadEnemy(E_num).radius, e_spawn->LoadEnemy(E_num).speed, e_spawn->LoadEnemy(E_num).bullet_speed, e_spawn->LoadEnemy(E_num).score, e_spawn->LoadEnemy(E_num).hp, E_num);
					// 敵の番号を見て必要なギミックを割り当てる
					if (gimmick == nullptr) {
						gimmick = new GIMMICK(E_num);
					}
					/*	E_numcnt = E_numcnt + 1;
					if (E_num != e_spawn->GetMaxEnemy()) {
						E_num = E_num + 1;
					}
					 e_spownCnt = 0;*/
				}
			}
	}

