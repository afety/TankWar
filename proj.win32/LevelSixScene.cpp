#include "proj.win32\LevelSixScene.h"
#include "proj.win32\Macros.h"

USING_NS_CC;

bool LevelSixScene::init() {

	if (!Scene::init()) {
		return false;
	}


	//add your code here:


	return true;
}

void LevelSixScene::onEnter() {
	Scene::onEnter();

	whichLevel = 6;
}

void LevelSixScene::onExit() {
	Scene::onExit();

}