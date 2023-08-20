#include "GIMMICK.h"
#include"common.h"
#include"DxLib.h"

GIMMICK::GIMMICK() {
	waitTime = 0;
}

GIMMICK::~GIMMICK() {

}

void GIMMICK::killwall() {
	if (++waitTime == FRAMERATE * 10) {
		if (waitTime % 2 == 0) {
			DrawFormatString(WIDTH / 4, HEIGHT / 2, 0xff0000, "Errer");
			DrawBox(0, 0, WIDTH / 2, HEIGHT, 0xfff0000, FALSE);
		}
	}
}
