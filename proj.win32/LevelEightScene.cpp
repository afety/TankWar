#include "proj.win32\LevelEightScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelEightScene::init() {

	if (!Scene::init()) {
		return false;
	}


	//add your code here:


	return true;
}

void LevelEightScene::onEnter() {
	Scene::onEnter();

	whichLevel = 8;
}

void LevelEightScene::onExit() {
	Scene::onExit();

}