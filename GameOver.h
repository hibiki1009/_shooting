#pragma once
#include"AbstractScene.h"
#include"DxLib.h"
#include"common.h"

class GameOver:public AbstractScene
{
public:
	GameOver();
	virtual ~GameOver();
	virtual AbstractScene* Update()override;
	virtual void Draw()const override;
private:
	int WaitTime;
	int image;

};

