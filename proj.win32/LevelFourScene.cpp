#include "proj.win32\LevelFourScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelFourScene::init() {

	if (!Scene::init()) {
		return false;
	}

	//add your code here:


	return true;
}

void LevelFourScene::onEnter() {
	Scene::onEnter();

	whichLevel = 4;
}

void LevelFourScene::onExit() {
	Scene::onExit();

}