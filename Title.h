#pragma once
#include"AbstractScene.h"
#include"DxLib.h"

class Title :public AbstractScene {
private:

	enum class MENU
	{
		PLAY,
		HELP,
		RANKING,
		EXIT,
		MENU_SIZE
	};
	// �񋓌^�N���X��int�ϊ��B�\���p
	const char* menu_items[static_cast<int>(MENU::MENU_SIZE)] = {
		"���ǂ�����",
		"�V�X�e���ɂ���",
		"���낭���݂�",
		"�����"
	};
	int bright;

	int T_images[7];
	int Title_Num;
	int Num_Update;
	int WaitTime;

	int cursorX;
	int cursorY;
	//�t�F�[�h�p�J�E���^
	int fade_counter;
	int fade_Mng;
	// �I�����Ă��郁�j���[
	int select_menu;
	//�I��SE�p�T�E���h�n���h��
	int select_se;
	//����SE�p�T�E���h�n���h��
	int decision_se;

	// �t�H���g�n���h��
	int menu_font;

	bool enter_flg;
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