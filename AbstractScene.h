#pragma once

//�f�t�H���g�̒��ۃV�[���N���X
//���[�U�[�͂�����p�����ăV�[������������Ɗy
class AbstractScene {

protected:

	//�摜
	int background_image;

	//SE&BGM
	int background_music;
	int gamemain_music;

	int cursor_move_se;
	int enter_se;

	int title_font;

	//
	short stage_num = 0;

private:
	int num = 0;
	void a() {
		num = 0;
	}

public:
	//�f�X�g���N�^
	virtual ~AbstractScene() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const = 0;//�C���^�[�t�F�C�X�N���X

	int GetDrawCenterX(const char* string, int font_handle)const;
	//interface�i�C���^�[�t�F�C�X�j�́A
	//�N���X���ǂ̂悤�ȃ��\�b�h�������Ă���̂������炩���ߒ�`����A
	//����ΐ݌v���̂悤�ȑ��݂ł��B �N���X�Ƃ͈قȂ�A��̓I�ȏ������e���L�q�����A
	//���\�b�h�̈�����߂�l�������`���܂��B

};
