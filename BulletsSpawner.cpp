#include "BulletsSpawner.h"
#include"common.h"
#include"GameMain.h"

int BulletsSpawner::Shoot(GameMain* gamemain)
{
	for (int i = 0; i < Bullet_Num; i++) {
		if (gamemain->bullet[i] != nullptr) {
			gamemain->bullet[i]->Update();
		}
	}
	return 0;
}
