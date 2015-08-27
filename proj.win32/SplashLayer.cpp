#include "proj.win32\SplashLayer.h"
#include "proj.win32\HomeScene.h"

#include <cstdlib>

USING_NS_CC;

bool SplashLayer::init() {

	if (!Layer::init()) {
		return false;
	}

	//get Size
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//change splash image here:
	auto splash = Sprite::create("Splash.png");
	splash->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(splash);

	auto start = Sprite::create("Splash_start.png");
	start->setPosition(Vec2(visibleSize.width / 2, 300));
	this->addChild(start);


	auto quit = Sprite::create("Splash_quit.png");
	quit->setPosition(Vec2(visibleSize.width / 2, 200));
	this->addChild(quit);


	//鼠标悬停，start按钮变大
	auto startlistener = EventListenerMouse::create();
	startlistener->onMouseMove = [=](Event* event) {
		Sprite* start = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 417 && mouse->getCursorX() < 607 &&
			mouse->getCursorY() > -484 && mouse->getCursorY() < -452) {
			if (aboveStart) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				start->runAction(scale);
				aboveStart = false;
				notAboveStart = true;
			}
		}
		else {
			if (notAboveStart) {
				auto scaleback = ScaleTo::create(0.1f, 1);
				start->runAction(scaleback);
				aboveStart = true;
				notAboveStart = false;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(startlistener, start);

	//鼠标悬停，quit按钮变大
	auto quitlistener = EventListenerMouse::create();
	quitlistener->onMouseMove = [=](Event* event) {
		Sprite* quit = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 446 && mouse->getCursorX() < 578 &&
			mouse->getCursorY() > -585 && mouse->getCursorY() < -551) {
			if (aboveQuit) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				quit->runAction(scale);
				aboveQuit = false;
				notAboveQuit = true;
			}
		}
		else {
			if (notAboveQuit) {
				auto scaleback = ScaleTo::create(0.1f, 1);
				quit->runAction(scaleback);
				aboveQuit = true;
				notAboveQuit = false;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(quitlistener, quit);


	//点击start按钮，场景切换进入关卡选择界面
	auto startclick = EventListenerMouse::create();
	startclick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 417 && mouse->getCursorX() < 607 &&
			mouse->getCursorY() > -484 && mouse->getCursorY() < -452) {

			//获取当前时间作为随机数种子
			srand((unsigned int)time(nullptr));
			//生成范围为[1, 20]的随机数,20中随机动画
			int a = (rand() % 20) + 1;
			switch (a) {
			case 1:
				Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, HomeScene::create()));
				break;
			case 2:
				Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, HomeScene::create()));
				break;
			case 3:
				Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, HomeScene::create()));
				break;
			case 4:
				Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, HomeScene::create()));
				break;
			case 5:
				Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, HomeScene::create()));
				break;
			case 6:
				Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, HomeScene::create()));
				break;
			case 7:
				Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, HomeScene::create()));
				break;
			case 8:
				Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, HomeScene::create()));
				break;
			case 9:
				Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, HomeScene::create()));
				break;
			case 10:
				Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, HomeScene::create()));
				break;
			case 11:
				Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, HomeScene::create()));
				break;
			case 12:
				Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, HomeScene::create()));
				break;
			case 13:
				Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, HomeScene::create()));
				break;
			case 14:
				Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, HomeScene::create()));
				break;
			case 15:
				Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, HomeScene::create()));
				break;
			case 16:
				Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, HomeScene::create()));
				break;
			case 17:
				Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, HomeScene::create()));
				break;
			case 18:
				Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, HomeScene::create()));
				break;
			case 19:
				Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, HomeScene::create()));
				break;
			case 20:
				Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, HomeScene::create(), true));
				break;
			default:
				log("ERROR!");
				break;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(startclick, start);


	//点击quit按钮退出整个app
	auto quitclick = EventListenerMouse::create();
	quitlistener->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 446 && mouse->getCursorX() < 578 &&
			mouse->getCursorY() > -585 && mouse->getCursorY() < -551) {

			Director::getInstance()->end();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(quitclick, quit);
	
	return true;
}