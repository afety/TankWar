#include "proj.win32\HomeScene.h"
#include "proj.win32\LevelsLayer.h"

USING_NS_CC;

bool HomeScene::init() {
	if (!Scene::init()) {
		return false;
	}

	auto levelsLayer = LevelsLayer::create();
	this->addChild(levelsLayer);

	return true;
}