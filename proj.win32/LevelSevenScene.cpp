#include "proj.win32\LevelSevenScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelSevenScene::init() {

	if (!Scene::init()) {
		return false;
	}


	//add your code here:


	return true;
}

void LevelSevenScene::onEnter() {
	Scene::onEnter();

	whichLevel = 7;
}

void LevelSevenScene::onExit() {
	Scene::onExit();

}