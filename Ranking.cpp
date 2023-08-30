#include "Ranking.h"
#include"DxLib.h"


// ランキングデータ変数宣言
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

	// 選択法ソート
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			// 1つ前のscoreより大きいまたは＝なら
			if (g_Ranking[i].score <= g_Ranking[j].score) {
				// 実体化構造体workに避難用
				work = g_Ranking[i];
				// 前のデータの位置に今のデータを入れる
				g_Ranking[i] = g_Ranking[j];
				// 避難させたデータをjに移動させることで順番が入れ替わる
				g_Ranking[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < 10; i++) {
		g_Ranking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
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
	// フォントサイズの設定
	SetFontSize(20);

	// 名前入力指示文字列の描画
	DrawString(150, 240, "ランキングに登録します", 0x000000);
	DrawString(150, 270, "名前を英字で入力してください", 0x000000);

	// 名前の入力
	DrawString(150, 310, "> ", 0xFFFFFF);
	DrawBox(160, 305, 300, 335, 0x000055, TRUE);
	if (KeyInputSingleCharString(170, 310, 10, g_Ranking[9].name, FALSE) == 1) {
		g_Ranking[9].score = g_Score;	// ランキングデータの１０番目にスコアを登録
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
		fprintf(fp, "%2d %10s %10d\n", g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
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
	FILE* fp;
		//ファイルオープン
		if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
			//エラー処理
			printf("Ranking Data Error\n");
		}

		//ランキングデータ配分列データを読み込む
		for (int i = 0; i < 10; i++) {
			fscanf(fp, "%2d %10s %10d", &g_Ranking[i].no, g_Ranking[i].name, &g_Ranking[i].score);
		}

		//ファイルクローズ
		fclose(fp);
	SetFontSize(30);
	for (int i = 0; i < 10; i++) {
		DrawFormatString(80, 170 + i * 25, 0x000000, "%2d   %10s     %10d",
			g_Ranking[i].no, g_Ranking[i].name, g_Ranking[i].score);
	}
	clsDx();
}
