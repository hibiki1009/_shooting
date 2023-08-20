#pragma once
#include"AbstractScene.h"
#include"DxLib.h"

class Title:public AbstractScene{
private:
	int T_images[7];
	int Title_Num;
	int Num_Update;
	int WaitTime;

	int cursorX;
	int cursorY;

public:
	// コンストラクタ
	Title();
	// デストラクタ
	virtual ~Title();

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
	float inputX();
	float inputY();

};

