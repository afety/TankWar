#include "proj.win32\SplashScene.h"
#include "proj.win32\SplashLayer.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
USING_NS_CC;

bool SplashScene::init() {

	//init the super first.
	if (!Scene::init()) {
		return false;
	}

	auto splashLayer = SplashLayer::create();
	this->addChild(splashLayer);

	return true;
}

//进入时
void SplashScene::onEnter() {
	//首先调用父类的方法
	Scene::onEnter();

	//设置背景音乐音频文件及是否循环播放
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("dragon.mp3", false);

	//设置音量大小,参数范围为0.0至1.0
	//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
}

//退出时
void SplashScene::onExit() {
	Scene::onExit();

	//退出场景停止背景音乐，为下一场景执行另一背景音乐做准备
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	//关闭音效引擎
	//SimpleAudioEngine::getInstance()->end()
}