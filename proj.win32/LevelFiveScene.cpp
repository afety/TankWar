#include "proj.win32\LevelFiveScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelFiveScene::init() {

	if (!Scene::init()) {
		return false;
	}


	//add your code here:

	return true;
}

void LevelFiveScene::onEnter() {
	Scene::onEnter();

	whichLevel = 5;
}

void LevelFiveScene::onExit() {
	Scene::onExit();

}