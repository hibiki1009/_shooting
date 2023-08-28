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

	// 選択法ソート
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			if (ranking_data[i].score <= ranking_data[j].score) {
				work = ranking_data[i];
				ranking_data[i] = ranking_data[j];
				ranking_data[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < 10; i++) {
		ranking_data[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
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
	// フォントサイズの設定
	SetFontSize(20);

	// 名前入力指示文字列の描画
	DrawString(150, 240, "ランキングに登録します", 0xFFFFFF);
	DrawString(150, 270, "名前を英字で入力してください", 0xFFFFFF);

	// 名前の入力
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, ranking_data[9].name, FALSE) == 1) {
		ranking_data[9].score = g_Score;	// ランキングデータの１０番目にスコアを登録
	}
}

int Ranking::SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* エラー処理 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// ランキングデータ分配列データを書き込む
	for (int i = 0; i < 10; i++) {
		fprintf(fp, "%2d %10s %10d\n", ranking_data[i].no, ranking_data[i].name, ranking_data[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}



AbstractScene* Ranking::Update()
{
	
		InputRanking();
		SortRanking();		// ランキング並べ替え
		SaveRanking();		// ランキングデータの保存

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
