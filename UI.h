#pragma once
class UI
{
public:
	// �R���X�g���N�^
	UI();
	void Update();
	void Draw();

	// GameMain����X�R�A�������Ă���@�X�R�A�G�t�F�N�g���A�j���[�V�����A�`����s��
	void Scor_Anim();
	// �X�R�A���Z�b�g����
	void SetScore(int _score);
	void SetLife(int life);
	void SetHp(int _hp);
	void SetP_location(float _x, float _y);
private:
	int WaitTime;
	int score;
	int life;
	int hp;
	int hp_Img;
	int hp_Img2;

	int hp_mng;


	float x, y;
};

