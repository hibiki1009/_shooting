#pragma once
#include"AbstractScene.h"
#define RANKING_DATA 10

// �����L���O�f�[�^�i�\���́j
struct	RankingData {
	int		no;
	char	name[11];
	long	score;
};


class Ranking:public AbstractScene
{
public:
	Ranking(int score);
	void InputRanking();
	void SortRanking();
	int  SaveRanking();


	

	// �f�X�g���N�^
	virtual ~Ranking();

	// �`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	// �`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const override;
private:

	int file;
	int row;						// csv�t�@�C���̗�̐�(�ǂݍ��܂��G�̗�)
	RankingData ranking_data[RANKING_DATA];
	int g_Score;
};

