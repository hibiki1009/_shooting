#pragma once
#include"DxLib.h"
#include"SphereCollider.h"

// memo
// 敵の番号　プレイヤーの座標・HP　

// ボス戦でサークルが出現、カウントダウンが始まり、
// 0の時プレイヤーが円に入っていたら確定キル

// 円は二種類　プレイヤーを追尾し、時間が長いもの（20秒で大きい）
// プレイヤーの追尾がなく時間が短いもの(5秒かつ小さめ)
class GIMMICK :public SphereCollider
{
public:
	// コンストラクタ
	GIMMICK(int e_num);
	// デストラクタ
	~GIMMICK();
	void KillCircle_Update();
	void KillCircle_Draw();

	void Set_P_Location(float _x,float _y);
	void Set_P_Hp(int _hp);
	int Get_Damage();
	float Get_Circle_time();
	bool Get_CircleKill();
private:
	int E_num;
	int waitTime;
	float circle_time;	//　サークルの時間を管理する
	int Spown_circle_time;	// サークルのリスポーン処理用
	float Px, Py;
	int P_hp;
	int Damage;
	bool kill;
};

