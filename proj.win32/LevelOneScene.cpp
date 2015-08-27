#include "proj.win32\LevelOneScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelOneScene::init() {

	if (!Scene::init()) {
		return false;
	}

	//add your code here:

	return true;
}

void LevelOneScene::onEnter() {
	Scene::onEnter();

	whichLevel = 1;
}

void LevelOneScene::onExit() {
	Scene::onExit();

}