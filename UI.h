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
private:
	int score;
	int life;
};

