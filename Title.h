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
	// �R���X�g���N�^
	Title();
	// �f�X�g���N�^
	virtual ~Title();

	virtual AbstractScene* Update()override;

	virtual void Draw()const override;
	float inputX();
	float inputY();

};

