#pragma once
#include <vector>
#include "AbstractScene.h"
#include"DxLib.h"

#include"Player.h"
#include"Bullet.h"


class GameMain :public AbstractScene {
private:
	

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
};

