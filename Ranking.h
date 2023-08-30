#pragma once
#include"AbstractScene.h"
#define RANKING_DATA 10

// ランキングデータ（構造体）
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


	

	// デストラクタ
	virtual ~Ranking();

	// 描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	// 描画に関することを実装する
	virtual void Draw()const override;
private:

	int file;
	int row;						// csvファイルの列の数(読み込まれる敵の量)
	RankingData ranking_data[RANKING_DATA];
	int g_Score;
};

