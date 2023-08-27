#include "GIMMICK.h"
#include"common.h"
#include"DxLib.h"

GIMMICK::GIMMICK(int e_num) {
	E_num = e_num;
	waitTime = 0;
	circle_time = FRAMERATE * 20;
	radius = 128;
	Damage = 100;
	kill = false;
	// 仮　敵かプレイヤーのlocationとるかも
	location.x = SCREEN_WIDTH/2;
	location.y = SCREEN_HEIGHT/2;
}

GIMMICK::~GIMMICK() {

}

void GIMMICK::KillCircle_Draw() {
	if (E_num == 5 && circle_time>0) {
		Spown_circle_time = 0;
		DrawCircle(location.x, location.y, radius, 0xff0000);
		DrawFormatString(location.x - radius, location.y - radius-20, 0x000000, "Danger!:%f", circle_time/FRAMERATE);
	}
	else {
		// リスポーン処理
		/*++Spown_circle_time;*/
	}
}

void GIMMICK::KillCircle_Update() {
	--circle_time;
	if (circle_time < 0.1) {
		kill = true;
	}

	if (location.x < Px) {
		location.x = location.x+2;
	}else {
		location.x = location.x - 2;
	}
	if (location.y < Py) {
		location.y = location.y + 2;
	}
	else {
		location.y = location.y - 2;
	}


}

void GIMMICK::Set_P_Location(float _x, float _y) {
	Px = _x;
	Py = _y;
}

void GIMMICK::Set_P_Hp(int _hp) {
	P_hp = _hp;
}
int GIMMICK::Get_Damage() {
	return Damage;
}

float GIMMICK::Get_Circle_time()
{
	return circle_time;
}

bool GIMMICK::Get_CircleKill()
{
	return kill;
}
