#include "proj.win32\LevelThreeScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelThreeScene::init() {

	if (!Scene::init()) {
		return false;
	}


	//add your code here:


	return true;
}

void LevelThreeScene::onEnter() {
	Scene::onEnter();

	whichLevel = 3;
}

void LevelThreeScene::onExit() {
	Scene::onExit();

}