#include "Ranking.h"
#include"DxLib.h"


// �����L���O�f�[�^�ϐ��錾
struct RankingData g_Ranking[10];

Ranking::Ranking(int _score)
{
	SetDrawBright(255, 255, 255);
	g_Score = _score;
}

Ranking::~Ranking()
{

}

void Ranking::SortRanking(void)
{
	int i, j;
	RankingData work;

	// �I��@�\�[�g
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			// 1�O��score���傫���܂��́��Ȃ�
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				// ���̉��\����work�ɔ��p
				work = g_Ranking[i];
				// �O�̃f�[�^�̈ʒu�ɍ��̃f�[�^������
				g_Ranking[i] = g_Ranking[j];
				// �������f�[�^��j�Ɉړ������邱�Ƃŏ��Ԃ�����ւ��
				g_Ranking[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < 10; i++) {
		g_Ranking[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			if (g_Ranking[i].score > g_Ranking[j].score) {
				g_Ranking[j].no++;
			}
		}
	}
}

void Ranking::InputRanking(void)
{
	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(20);

	// ���O���͎w��������̕`��
	DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0x000000);
	DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0x000000);

	// ���O�̓���
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[9].name, FALSE) == 1) {
		g_Ranking[9].score = g_Score;	// �����L���O�f�[�^�̂P�O�ԖڂɃX�R�A��o�^
	}
}

int Ranking::SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// �t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* �G���[���� */
		printf("Ranking Data Error\n");
		return -1;
	}

	// �����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < 10; i++) {
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}



AbstractScene* Ranking::Update()
{
	
		InputRanking();
		SortRanking();		// �����L���O���בւ�
		SaveRanking();		// �����L���O�f�[�^�̕ۑ�
	return this;
}

void Ranking::Draw() const
{
	FILE* fp;
		//�t�@�C���I�[�v��
		if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
			//�G���[����
			printf("Ranking Data Error\n");
		}

		//�����L���O�f�[�^�z����f�[�^��ǂݍ���
		for (int i = 0; i < 10; i++) {
			fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
		}

		//�t�@�C���N���[�Y
		fclose(fp);
	SetFontSize(30);
	for (int i = 0; i < 10; i++) {
		DrawFormatString(80, 170 + i * 25, 0x000000, "%2d   %10s     %10d",
			g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}
	clsDx();
}
