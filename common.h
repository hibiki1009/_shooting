#pragma once

#define SCREEN_WIDTH 1280		// ��ʕ��T�C�Y
#define SCREEN_HEIGHT 720		// ��ʍ����T�C�Y
#define SCREEN_COLORBIT 32		
#define FRAMERATE 60.0			//�t���[�����[�g
#define UPDATETIME 800

#define HEIGHT  10				//	�u���b�N�z��c
#define WIDTH  16				// �u���b�N�z��
#define STAGE  5				// �X�e�[�W�z��

constexpr auto Bullet_Num = 900;
constexpr auto Enemy_Num = 50;

// memo

// ****************** consyexpr auto�ɂ��� ***********************

// const���u���̕ϐ��͍���ύX���܂��񂵁A�ύX���悤�Ƃ�����R���p�C���G���[�ɂ��Ă��������ˁv
// �Ƃ������}�ł���̂ɑ΂��A�ϐ��ɕt����constexpr�́u���̕ϐ��̒l�̓R���p�C�����Ɋm�肷�邵�A
// �m�肵�Ȃ���΃R���p�C���G���[�ɂ��Ă��������ˁv�Ƃ������}�B

//constexpr �̂ق��͂��̗̈�i�̃A�h���X�j���g���񂳂�邾���ł����A 
//define�̕��͂��̓s�x�������ɓW�J����A���̌��ʖ��ʂɃ��������g�����ƂɂȂ�B