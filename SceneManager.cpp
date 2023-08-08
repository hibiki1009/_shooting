#include "SceneManager.h"

AbstractScene* SceneManager::Update() {// AbstractSceneのUpdateをSceneManagerで使う
	AbstractScene* p = mScene->Update();// 今のシーンをｐに代入
	if (p != mScene) {//　ｐが今のシーンと違うなら
		delete mScene;// 今のシーンを消去
		mScene = p;// pを今のシーンに代入
	}

	return p;// pのシーンを返す
}
void SceneManager::Draw()const {
	mScene->Draw();//今のシーンを描画する

}

