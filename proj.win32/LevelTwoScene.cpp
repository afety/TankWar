#include "proj.win32\LevelTwoScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelTwoScene::init() {

	if (!Scene::init()) {
		return false;
	}

	//add your code here:


	return true;
}

void LevelTwoScene::onEnter() {
	Scene::onEnter();

	whichLevel = 2;
}

void LevelTwoScene::onExit() {
	Scene::onExit();

}