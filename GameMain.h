#pragma once
#include <vector>
#include "AbstractScene.h"
#include"DxLib.h"
#include"common.h"

#include"Player.h"
#include"Enemy.h"
#include"Bullet.h"
#include"BulletsSpawner.h"
#include<vector>

class GameMain :public AbstractScene {
private:
	int life;				// 残機
	int shoot_i;
	int WaitTime;
public:

	// クラスオブジェクト
	Player* player;
	Enemy* enemy;
	// Bulletを配列化
	Bullet *bullet[1000];
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

};

