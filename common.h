#pragma once

#define SCREEN_WIDTH 1280		// 画面幅サイズ
#define SCREEN_HEIGHT 720		// 画面高さサイズ
#define SCREEN_COLORBIT 32		
#define FRAMERATE 60.0			//フレームレート
#define UPDATETIME 800

#define HEIGHT  10				//	ブロック配列縦
#define WIDTH  16				// ブロック配列横
#define STAGE  5				// ステージ配列

constexpr auto Bullet_Num = 900;
constexpr auto Enemy_Num = 50;

// memo

// ****************** consyexpr autoについて ***********************

// constが「この変数は今後変更しませんし、変更しようとしたらコンパイルエラーにしてくださいね」
// という合図であるのに対し、変数に付けるconstexprは「この変数の値はコンパイル時に確定するし、
// 確定しなければコンパイルエラーにしてくださいね」という合図。

//constexpr のほうはその領域（のアドレス）が使い回されるだけですが、 
//defineの方はその都度メモリに展開され、その結果無駄にメモリを使うことになる。