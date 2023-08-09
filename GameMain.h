#pragma once
#include <vector>
#include "AbstractScene.h"
#include"DxLib.h"

#include"Player.h"
#include"Bullet.h"


class GameMain :public AbstractScene {
private:
	int life;				// 残機
	int* enemy[5];			// ポインタ配列
	int* bullets[10];			// ポインタ配列

public:

	// クラスオブジェクト
	Player* player;
	Bullet* bullet;

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

