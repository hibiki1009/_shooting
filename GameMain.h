#pragma once
#include <vector>
#include "AbstractScene.h"
#include"DxLib.h"
#include"common.h"

#include"Title.h"
#include"Ranking.h"

#include"UI.h"
#include"CharaBase.h"
#include"Player.h"
#include"Enemy.h"
#include"EnemySpawn.h"
#include"Bullet.h"
#include"GIMMICK.h"
#include"BulletsSpawner.h"
#include"NwaySpawner.h"
#include<vector>

class GameMain :public AbstractScene {
private:
	int life;				// 残機
	int shoot_i;
	int Eshoot_i;
	int E_num;
	int E_numcnt;
	int WaitTime;
	// 仮変数
	int Score;
	float gridX;
	float gridY;
	float Gole_distance;// ゴールまでの距離

	int e_spownCnt;
public:

	// クラスオブジェクト
	Player* player;
	Enemy* enemy[Enemy_Num];
	GIMMICK* gimmick;
	UI* ui;
	Bullet* bullet[Bullet_Num];

	Bullet* Ebullet[Bullet_Num];

	BulletsSpawner* b_spawner;
	EnemySpawn* e_spawn;

	GameMain* gamemain;
	Ranking* ranking;
	/*BulletsSpawner *B_spawner;*/

	void Game();
	// コンストラクタ
	GameMain();

	// デストラクタ
	virtual ~GameMain();

	// 描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	// 描画に関することを実装する
	virtual void Draw()const override;

	int HitCheck();			// 弾 / プレイヤー / 敵の当たり判定のチェックを行う

	void SpawnBullet();			// 弾の配列に新しくデータを作成する
	void SpawnEnemy();

	int GetShoot();
};

