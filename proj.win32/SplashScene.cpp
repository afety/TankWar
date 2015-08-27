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

//����ʱ
void SplashScene::onEnter() {
	//���ȵ��ø���ķ���
	Scene::onEnter();

	//���ñ���������Ƶ�ļ����Ƿ�ѭ������
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("dragon.mp3", false);

	//����������С,������ΧΪ0.0��1.0
	//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
}

//�˳�ʱ
void SplashScene::onExit() {
	Scene::onExit();

	//�˳�����ֹͣ�������֣�Ϊ��һ����ִ����һ����������׼��
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	//�ر���Ч����
	//SimpleAudioEngine::getInstance()->end()
}