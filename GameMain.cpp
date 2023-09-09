#include "GameMain.h"
#include"SphereCollider.h"
#include"PAD_INPUT.h"
#include"EnemySpawn.h"


GameMain::GameMain()
{
	SetDrawBright(255, 255, 255);
	Gole_distance = 500;
	Score = 0;
	life = 3;

	WaitTime = 0;
	E_num = 1;
	e_spownCnt = 0;
	shoot_i = 1;
	Eshoot_i = 1;
	E_numcnt = 1;

	gridX = 80;
	gridY = -10;
	Gr_waittime = 0;
	player = new Player;
	gimmick = nullptr;
	ui = new UI;
	b_spawner = new BulletsSpawner;
	e_spawn = new EnemySpawn;
	setumei = true;

	for (int i = 0; i < Enemy_Num; i++) {
		enemy[i] = nullptr;
	}

	for (int i = 0; i < Bullet_Num; i++) {
		bullet[i] = nullptr;
	}

		for (int i = 0; i < E_Bullet_Num; i++) {
			Ebullet[i] = nullptr;
		}
}

GameMain::~GameMain()
{
	
}

AbstractScene* GameMain::Update()
{
	if (++WaitTime > FRAMERATE * 10) {
		setumei = false;
	}

		gridY = gridY + 10;
	if (gridY > SCREEN_HEIGHT+100) {
		gridY = 0;
	}

	Gole_distance = Gole_distance - 0.1f;
	if (Gole_distance < 0) {
		return new Ranking(Score, true);
	}
	Game();
	if (life < 1) {
		return new GameOver;
	}
	return this;
}

void GameMain::Game()
{
	
	
	player->Update();

	if (gimmick != nullptr) {
		// �ǔ��M�~�b�N�悤�Ƀv���C���[�̍��W�擾
		gimmick->Set_P_Location(player->GetLocation().x, player->GetLocation().y);
		// �M�~�b�N�悤�Ƀv���C���[��Hp���擾
		gimmick->Set_P_Hp(player->GetHp());
		// �M�~�b�N�̃A�b�v�f�[�g����
		gimmick->KillCircle_Update();
	}

	
	// �v���C���[��HP����
	if (player->GetHp() <= 0) {
			life = life - 1;
			// �v���C���[�̏�����
			player->PlayerInit();
	}
	SpawnEnemy();

	for (int i = 0; i < Enemy_Num; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();

			// �G�l�~�[�̈ړ�
			enemy[i]->Enemy_move(player->GetLocation().x, player->GetLocation().y);
			enemy[i]->SetPlayerlocation(player->GetLocation().x, player->GetLocation().y);

			// �G���A�O�Ȃ�e�L���_���[�W
			if (enemy[i]->GetLocation().y > SCREEN_HEIGHT) {
				enemy[i]->Sethp(enemy[i]->Gethp()+1);
			}

			if (enemy[i]->GetLocation().x > SCREEN_WIDTH) {
				enemy[i]->Sethp(enemy[i]->Gethp() + 1);
			}

			if (enemy[i]->GetLocation().x < 0) {
				enemy[i]->Sethp(enemy[i]->Gethp() + 1);
			}

			// �G�l�~�[��HP���擾�A0�Ȃ�X�R�A���Z
			if (enemy[i]->Gethp() <= 0) {
				// �G���A�O�ɂ�鋭���ޏ�łȂ��Ȃ�X�R�A���Z
				if (enemy[i]->GetLocation().y < SCREEN_HEIGHT) {
					Score = Score + enemy[i]->GetPoint();
				}
				enemy[i] = nullptr;
			}
			
		}
	}

		SpawnBullet();

	for (int i = 0; i < Bullet_Num; i++) {
		//���g������Ȃ�Update��������
		if (bullet[i] != nullptr) {
			bullet[i]->Update();
		}
	}
		for (int i = 0; i < E_Bullet_Num; i++) {
			//���g������Ȃ�Update��������
			if (Ebullet[i] != nullptr) {
				Ebullet[i]->Update();
			}
		}

	// �e�ۂ̔��菈��
	HitCheck();

	// UI�Z�b�g�֐�
	SetFontSize(20);
	ui->SetScore(Score);
	ui->SetLife(life);
	ui->SetHp(player->GetHp());
	ui->SetP_location(player->GetLocation().x, player->GetLocation().y);
	clsDx();
}

void GameMain::Draw() const
{
	
	if (gimmick != nullptr) {
		// �L���T�[�N���M�~�b�N��Draw
		gimmick->KillCircle_Draw();
	}
	// �w�i�O���b�h��
	for (int i = 0; i <= 16; i++) {
		// �c��
		DrawLine(gridX * i, 0, gridX * i, SCREEN_HEIGHT, 0xcccccc, TRUE);
	}
		DrawBox(0, gridY, gridY+SCREEN_WIDTH, gridY+5, 0xcccccc,true);

	SetFontSize(20);
	if (setumei == true) {
		DrawString(player->GetLocation().x-100, player->GetLocation().y-70, "���X�e�B�b�N�ňړ� : �E�X�e�B�b�N�ő_�����߂�", 0xff0000);
		DrawString(player->GetLocation().x - 100, player->GetLocation().y - 50, "RB�ŋ��𔭎˂���", 0xff0000);
	}
	DrawFormatString(0, 100, 0xff0000, "�m�R��:%f TB", Gole_distance);
	clsDx();

	ui->Draw();
	if (player != nullptr) {
		player->Draw();
	}
	// null����Ȃ��G�l�~�[�̂�Draw����
	for (int i = 0; i < Enemy_Num; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
			
		}
	}


	for (int i = 0; i < Bullet_Num; i++) {
		// ���g������Ȃ�Draw��������
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
	
		for (int i = 0; i < E_Bullet_Num; i++) {
			// ���g������Ȃ�Draw��������
			if (Ebullet[i] != nullptr) {
				Ebullet[i]->Draw();

			}
		}

}

int GameMain::HitCheck()
{
	// �M�~�b�N�ƃv���C���[�̔��菈��
	if (gimmick != nullptr) {
		// �M�~�b�N�̎��Ԃ�0�Ȃ����
		if (gimmick->Get_CircleKill() == true) {
			if (gimmick->HitSphere(player)) {
				player->Hit(gimmick->Get_Damage());
			}
			gimmick = nullptr;
		}
		
	}

	// �v���C���[�̏���
	
		for (int i = 0; i < E_Bullet_Num; i++) {
			if (Ebullet[i] != nullptr) {
				// ���g������Ȃ�Hit��������
				if (Ebullet[i]->HitSphere(player) == true)
				{
					player->Hit(Ebullet[i]->GetDamage());
					Ebullet[i] = nullptr;
				}
			}
		
		// �G�l�~�[�̏���
		for (int j = 0; j < Enemy_Num;j++) {
			// �G�l�~�[��null����Ȃ��Ȃ����
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
	if (Eshoot_i == E_Bullet_Num) {
		Eshoot_i = 1;
	}

	// RB��������Ă���ԓ���
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_RIGHT_SHOULDER)) {
		if (player->shoot() == true) {
			// ���g���Ȃ��Ȃ�V����player���W��������Bullet�N���X��������
			if (bullet[shoot_i] == nullptr) {

				bullet[shoot_i] = new Bullet(player->GetLocation().x, player->GetLocation().y, false, player->getRadian(), player->GetBullet_speed());
				shoot_i = shoot_i + 1;
			}
		}
		for (int i = 0; i <= Bullet_Num; i++)
		{
			if (bullet[i] != nullptr) {
				if (bullet[i]->GetLocationX() > SCREEN_WIDTH) {
					bullet[i] = nullptr;
				}
			}
			if (bullet[i] != nullptr) {
				if (bullet[i]->GetLocationX() < 0) {
					bullet[i] = nullptr;
				}
			}
			if (bullet[i] != nullptr) {
				if (bullet[i]->GetLocationY() > SCREEN_HEIGHT) {
					bullet[i] = nullptr;
				}
			}
			if (bullet[i] != nullptr) {
				if (bullet[i]->GetLocationY() < 0) {
					bullet[i] = nullptr;
				}
			}
		}
	}
	// ��������G�l�~�[
	for (int j = 0; j < Enemy_Num; j++) {
		// �G�l�~�[��null�łȂ�
		if (enemy[j] != nullptr) {
			if (enemy[j]->shoot() == true) {
				if (Ebullet[Eshoot_i] == nullptr)
					Ebullet[Eshoot_i] = new Bullet(enemy[j]->GetLocation().x, enemy[j]->GetLocation().y, true, enemy[j]->getRadian(), enemy[j]->GetBullet_speed());
				Eshoot_i = Eshoot_i + 1;
			}
		}
	}
	for (int i = 0; i <= Bullet_Num; i++)
	{
		if (Ebullet[i] != nullptr) {
			if (Ebullet[i]->GetLocationX() > SCREEN_WIDTH) {
				Ebullet[i] = nullptr;
			}
		}
		if (Ebullet[i] != nullptr) {
			if (Ebullet[i]->GetLocationX() < 0) {
				Ebullet[i] = nullptr;
			}
		}
		if (Ebullet[i] != nullptr) {
			if (Ebullet[i]->GetLocationY() > SCREEN_HEIGHT) {
				Ebullet[i] = nullptr;
			}
		}
		if (Ebullet[i] != nullptr) {
			if (Ebullet[i]->GetLocationY() < 0) {
				Ebullet[i] = nullptr;
			}
		}
	}
}

void GameMain::SpawnEnemy()
{
		if (enemy[E_num] == nullptr) {
				// �G�l�~�[�̏o�����Ԃɓ��B������
				if (++e_spownCnt > e_spawn->LoadEnemy(E_num).time * FRAMERATE) {
					//�o�������G�l�~�[�̏���S�đ��M
					enemy[E_num] = new Enemy(e_spawn->LoadEnemy(E_num).location_x, e_spawn->LoadEnemy(E_num).location_y, e_spawn->LoadEnemy(E_num).radius, e_spawn->LoadEnemy(E_num).speed, e_spawn->LoadEnemy(E_num).bullet_speed, e_spawn->LoadEnemy(E_num).score, e_spawn->LoadEnemy(E_num).hp, E_num);
					// �G�̔ԍ������ĕK�v�ȃM�~�b�N�����蓖�Ă� ���̂Ƃ���S��
					if (gimmick == nullptr && E_num == 7) {
						gimmick = new GIMMICK(E_num);
					}
						// �G�l�~�[�̐����}�b�N�X�l�łȂ��Ȃ�
					if (E_num < e_spawn->GetMaxEnemy() - 1) {
						E_num = E_num + 1;
					}
				}
			}
	}

int GameMain::GetShoot()
{
	return shoot_i;
}

