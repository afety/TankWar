#include "proj.win32\PauseScene.h"
#include "proj.win32\PauseLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

bool PauseScene::init() {

	if (!Scene::init()) {
		return false;
	}

	//add your code here to bulid pause scene:
	auto pauseLayer = PauseLayer::create();
	this->addChild(pauseLayer);

	return true;
}

void PauseScene::onEnter() {
	Scene::onEnter();

	//��ͣ��Ч�ͱ�������
	//SimpleAudioEngine::getInstance()->pauseAllEffects();
	//SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void PauseScene::onExit() {
	Scene::onExit();

	//������Ч�ͱ�������
	//SimpleAudioEngine::getInstance()->resumeAllEffects();
	//SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}