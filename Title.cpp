#include "Title.h"
#include"PAD_INPUT.h"
#include"GameMain.h"
#include"common.h"
#include"Ranking.h"

#define FADE_TIME 100

Title::Title()
{
	bright = 0;
	enter_se = LoadSoundMem("Sound/SE/enter.mp3");
	menu_font = LoadFontDataToHandle("font/funwari-round_s120.dft");
	cursor_move_se = LoadSoundMem("Sound/SE/Cursor_Move.mp3");
	enter_flg = false;
	// �Z���N�g�l���v���C�ɂ���
	select_menu = static_cast<int>(MENU::PLAY);
	// �t�F�[�h�A�E�g�p�ϐ�
	fade_counter = 0;
	fade_Mng = 1;
	// ���邳�����Z�b�g 0 0 0�͍�
	SetDrawBright(0, 0, 0);

	Title_Num = 0;
	Num_Update = 1;
	WaitTime = 0;
	cursorX = 130;
	cursorY = 420;


	test = LoadGraph("images/Title/error.avi");
	// �^�C�g����ʃA�j���[�V����
	T_images[0] = LoadGraph("images/Title/Title1.PNG", false);
	T_images[1] = LoadGraph("images/Title/Title2.PNG", false);
	T_images[2] = LoadGraph("images/Title/Title3.PNG", false);
	T_images[3] = LoadGraph("images/Title/Title4.PNG", false);
	T_images[4] = LoadGraph("images/Title/Title5.PNG", false);
	T_images[5] = LoadGraph("images/Title/Title6.PNG", false);
	T_images[6] = LoadGraph("images/Title/Title7.PNG", false);
}

Title::~Title()
{
	DeleteSoundMem(cursor_move_se);
}

AbstractScene* Title::Update()
{
	/*printfDx("  %d  ", test);*/
	if (fade_counter < FADE_TIME)
	{
		fade_counter = fade_counter+ fade_Mng;
	}

	// float�ϊ�fade�Ŋ������l��int�ɂ��Abright�Ƃ���
	bright = static_cast<int>((static_cast<float>(fade_counter) / FADE_TIME * 255));

	if (++WaitTime % 10 == 0) {
		Title_Num++;
	}
	if (Title_Num >= 6) {
		Title_Num = 0;
	}

	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_DOWN)&& enter_flg==false) {
		PlaySoundMem(cursor_move_se, DX_PLAYTYPE_BACK, TRUE);
		// ���j���[�I����������Ɉړ�
			// Play����Help�Ȃ�(0+1) % 4 = 1 Help����RANKING�Ȃ� (1+1) % 4 = 2 EXIT�@(3+1) % 4 = 0
		select_menu = (select_menu + 1) % static_cast<int>(MENU::MENU_SIZE);

	}
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_DPAD_UP) && enter_flg == false) {
		PlaySoundMem(cursor_move_se, DX_PLAYTYPE_BACK, TRUE);
		// ���j���[�I��������O�Ɉړ�  Play�@(0-1+4) % 4 = 3(EXIT)
		select_menu = (select_menu - 1 + static_cast<int>(MENU::MENU_SIZE)) % static_cast<int>(MENU::MENU_SIZE);

	}

	// select_menu��MENU�N���X�ɕϊ�
	MENU current_selection = static_cast<MENU>(select_menu);

	
		
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_B)) {
		enter_flg = true;
		fade_Mng = -1;
		fade_counter = FADE_TIME - 1;
		PlaySoundMem(enter_se, DX_PLAYTYPE_BACK, TRUE);
	}
	if (enter_flg == true) {
		switch (current_selection)
		{
		case Title::MENU::PLAY:

			if (bright < 0) {
				return new GameMain();
			}
			break;

		case Title::MENU::HELP:
			printfDx("�������ȋ@�\�ł��B\n");
			break;

		case Title::MENU::RANKING:
			if (bright < 0) {
				return new Ranking(0);
			}
			break;

		case Title::MENU::EXIT:
			printfDx("�������ȋ@�\�ł��B\n");
			break;
		}
	}
	return this;
}

	

void Title::Draw() const
{
	SetDrawBright(bright, bright, bright);
	

	
	
	
	DrawGraph(0, 0, T_images[Title_Num], false);
	/*PlayMovie("images/Title/error.ogv", 1, DX_MOVIEPLAYTYPE_NORMAL);*/

	for (int i = 0; i < static_cast<int>(MENU::MENU_SIZE); i++)
	{
		// ������̍ŏ�Y���W
		const int base_y = 350;

		// �������Y���W�Ԋu
		const int margin_y = 100;

		// �����F
		int color = 0xcccccc;
		// �����O�g�F
		int border_color = 0x00FF00;

		// �����x
		int transparency = 180;


		// �J�[�\���������Ă���ꍇ�A�����F�ƕ����O�g�F�𔽓]������
		if (select_menu == i) {
			color = ~color;
			border_color = ~border_color;
			// �J�[�\���������Ă���Ȃ瓧���x�Ȃ�
			transparency = 255;
		}

		//�A���t�@�u�����f�B���O����
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparency);
		// ���W�@�T�C�Y�@�F�@�t�H���g�n���h���Ƃ��F�X���߂����
		DrawExtendStringToHandle(200, i * margin_y + base_y, 0.5, 0.5, menu_items[i], color, menu_font, border_color);
		// �u�����h����
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

float Title::inputX() {
	return round(((float)PAD_INPUT::GetPadThumbLX() / 32767) * 100) / 100;
}

float Title::inputY() {
	return round(((float)PAD_INPUT::GetPadThumbLY() / 32767) * 100) / 100;
}


