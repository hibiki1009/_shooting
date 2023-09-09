#include "GameOver.h"
#include"PAD_INPUT.h"
#include"Title.h"
#include"Ranking.h"

GameOver::GameOver()
{
  image = LoadGraph("images/Game/gameover.jpeg");
}

GameOver::~GameOver()
{
}

AbstractScene* GameOver::Update()
{
    if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_B) == true) {
        return new Title;
}
    return this;
}

void GameOver::Draw() const
{
 
    DrawRotaGraph(620, SCREEN_WIDTH / 4,3,0,image, true);
    DrawString(SCREEN_HEIGHT-100, SCREEN_WIDTH / 2,"B‚ÅTITle‚Ö", 0xffffff);
}
