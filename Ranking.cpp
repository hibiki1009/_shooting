#include "Ranking.h"
#include"DxLib.h"


Ranking::Ranking(int score)
{
	SetDrawBright(255, 255, 255);
	g_Score = score;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			ranking_data[i].score = g_Score;
		}
	}
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
			if (ranking_data[i].score <= ranking_data[j].score) {
				work = ranking_data[i];
				ranking_data[i] = ranking_data[j];
				ranking_data[j] = work;
			}
		}
	}

	// ���ʕt��
	for (i = 0; i < 10; i++) {
		ranking_data[i].no = 1;
	}
	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			if (ranking_data[i].score > ranking_data[j].score) {
				ranking_data[j].no++;
			}
		}
	}
}

void Ranking::InputRanking(void)
{
	// �t�H���g�T�C�Y�̐ݒ�
	SetFontSize(20);

	// ���O���͎w��������̕`��
	DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
	DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0xFFFFFF);

	// ���O�̓���
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, ranking_data[9].name, FALSE) == 1) {
		ranking_data[9].score = g_Score;	// �����L���O�f�[�^�̂P�O�ԖڂɃX�R�A��o�^
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
		fprintf(fp, "%2d %10s %10d\n", ranking_data[i].no, ranking_data[i].name, ranking_data[i].score);
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



	
		SetFontSize(30);
		for (int i = 0; i < 10; i++) {
			DrawFormatString(80, 170 + i * 25, 0x000000, "%2d   %10s     %10d",
				ranking_data[i].no, ranking_data[i].name, ranking_data[i].score);
		}

	/*DrawString(150, 450, "--  Press [SPACE] Key  --", 0xFF0000);*/

}
