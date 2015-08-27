#include "proj.win32\LevelsLayer.h"
#include "proj.win32\LevelOneScene.h"
#include "proj.win32\LevelTwoScene.h"
#include "proj.win32\LevelThreeScene.h"
#include "proj.win32\LevelFourScene.h"
#include "proj.win32\LevelFiveScene.h"
#include "proj.win32\LevelSixScene.h"
#include "proj.win32\LevelSevenScene.h"
#include "proj.win32\LevelEightScene.h"

#include <cstdlib>

USING_NS_CC;

bool LevelsLayer::init() {

	if (!Layer::init()) {
		return false;
	}

	//////////////////从数据库获取通关信息,测试的时候手动更改进行解锁关卡//////////////////////
	bool level2Unlock = 1;
	bool level3Unlock = 1;
	bool level4Unlock = 1;
	bool level5Unlock = 1;
	bool level6Unlock = 1;
	bool level7Unlock = 1;
	bool level8Unlock = 1;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	/////////////////背景图片的zOrder是0，其他精灵一律设置为1///////////////////////////

	//背景图片
	auto background = Sprite::create("Home_bg.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background);


	//以下是关卡选择图片的添加
	//第一关,默认解锁
	auto level1 = Sprite::create("Level1_unlock.png");
	level1->setPosition(Vec2(181, 632));
	this->addChild(level1);

	//第二关，根据是否解锁的状态来设置精灵的图片
	Sprite* level2;
	if (level2Unlock) {
		level2 = Sprite::create("Level2_unlock.png");
	}
	else {
		level2 = Sprite::create("Level2_lock.png");
	}
	level2->setPosition(Vec2(324, 532));
	this->addChild(level2);

	//第三关
	Sprite* level3;
	if (level3Unlock) {
		level3 = Sprite::create("Level3_unlock.png");
	}
	else {
		level3 = Sprite::create("Level3_lock.png");
	}
	level3->setPosition(Vec2(470, 473));
	this->addChild(level3);

	//第四关
	Sprite* level4;
	if (level4Unlock) {
		level4 = Sprite::create("Level4_unlock.png");
	}
	else {
		level4 = Sprite::create("Level4_lock.png");
	}
	level4->setPosition(Vec2(623, 387));
	this->addChild(level4);

	//第五关
	Sprite* level5;
	if (level5Unlock) {
		level5 = Sprite::create("Level5_unlock.png");
	}
	else {
		level5 = Sprite::create("Level5_lock.png");
	}
	level5->setPosition(Vec2(468, 301));
	this->addChild(level5);

	//第六关
	Sprite* level6;
	if (level6Unlock) {
		level6 = Sprite::create("Level6_unlock.png");
	}
	else {
		level6 = Sprite::create("Level6_lock.png");
	}
	level6->setPosition(Vec2(323, 227));
	this->addChild(level6);

	//第七关
	Sprite* level7;
	if (level7Unlock) {
		level7 = Sprite::create("Level7_unlock.png");
	}
	else {
		level7 = Sprite::create("Level7_lock.png");
	}
	level7->setPosition(Vec2(180, 137));
	this->addChild(level7);

	//第八关
	Sprite* level8;
	if (level8Unlock) {
		level8 = Sprite::create("Level8_unlock.png");
	}
	else {
		level8 = Sprite::create("Level8_lock.png");
	}
	level8->setPosition(Vec2(220, 374));
	this->addChild(level8);



	//退出按钮设置
	auto quit = Sprite::create("Home_quit.png");
	quit->setPosition(Vec2(852, 166));
	this->addChild(quit);

	//关卡选择文字精灵
	auto sceneName = Sprite::create("Home_select.png");
	sceneName->setPosition(Vec2(852, 605));
	this->addChild(sceneName);


	//为8个关卡图片设置鼠标悬停事件，悬停之后图片放大
	auto level1Listener = EventListenerMouse::create();
	level1Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 108 && mouse->getCursorX() < 254 &&
			mouse->getCursorY() < -70 && mouse->getCursorY() > -202) {
			if (aboveLevelOne) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelOne = false;
				notAboveLevelOne = true;
			}
		}
		else {
			if (notAboveLevelOne) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				aboveLevelOne = true;
				notAboveLevelOne = false;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level1Listener, level1);


	//关卡2图片悬停事件
	auto level2Listener = EventListenerMouse::create();
	level2Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 252 && mouse->getCursorX() < 396 &&
			mouse->getCursorY() > -286 && mouse->getCursorY() < -185) {
			if (aboveLevelTwo) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelTwo = false;
				notAboveLevelTwo = true;
			}
		}
		else {
			if (notAboveLevelTwo) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveLevelTwo = false;
				aboveLevelTwo = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level2Listener, level2);

	//关卡3悬停事件
	auto level3Listener = EventListenerMouse::create();
	level3Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 398 && mouse->getCursorX() < 542 &&
			mouse->getCursorY() > -350 && mouse->getCursorY() < -240) {
			if (aboveLevelThree) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelThree = false;
				notAboveLevelThree = true;
			}
		}
		else {
			if (notAboveLevelThree) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveLevelThree = false;
				aboveLevelThree = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level3Listener, level3);

	//关卡4悬停事件
	auto level4Listener = EventListenerMouse::create();
	level4Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 547 && mouse->getCursorX() < 699 &&
			mouse->getCursorY() > -440 && mouse->getCursorY() < -322) {
			if (aboveLevelFour) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelFour = false;
				notAboveLevelFour = true;
			}
		}
		else {
			if (notAboveLevelFour) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveLevelFour = false;
				aboveLevelFour = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level4Listener, level4);

	//关卡5悬停事件
	auto level5Listener = EventListenerMouse::create();
	level5Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 396 && mouse->getCursorX() < 540 &&
			mouse->getCursorY() > -516 && mouse->getCursorY() < -418) {
			if (aboveLevelFive) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelFive = false;
				notAboveLevelFive = true;
			}
		}
		else {
			if (notAboveLevelFive) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveLevelFive = false;
				aboveLevelFive = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level5Listener, level5);

	//关卡6悬停事件
	auto level6Listener = EventListenerMouse::create();
	level6Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() < 391 && mouse->getCursorX() > 255 &&
			mouse->getCursorY() < -490 && mouse->getCursorY() > -592) {
			if (aboveLevelSix) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelSix = false;
				notAboveLevelSix = true;
			}
		}
		else {
			if (notAboveLevelSix) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveLevelSix = false;
				aboveLevelSix = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level6Listener, level6);

	//关卡7悬停事件
	auto level7Listener = EventListenerMouse::create();
	level7Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 107 && mouse->getCursorX() < 253 &&
			mouse->getCursorY() > -685 && mouse->getCursorY() < -577) {
			if (aboveLevelSeven) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelSeven = false;
				notAboveLevelSeven = true;
			}
		}
		else {
			if (notAboveLevelSeven) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveLevelSeven = false;
				aboveLevelSeven = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level7Listener, level7);

	//关卡8悬停事件
	auto level8Listener = EventListenerMouse::create();
	level8Listener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 137 && mouse->getCursorX() < 303 &&
			mouse->getCursorY() > -452 && mouse->getCursorY() < -336) {
			if (aboveLevelEight) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveLevelEight = false;
				notAboveLevelEight = true;
			}
		}
		else {
			if (notAboveLevelEight) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveLevelEight = false;
				aboveLevelEight = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level8Listener, level8);

	//退出按钮悬停事件
	auto quitListener = EventListenerMouse::create();
	quitListener->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 747 && mouse->getCursorX() < 957 &&
			mouse->getCursorY() > -629 && mouse->getCursorY() < -575) {
			if (aboveQuit) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveQuit = false;
				notAboveQuit = true;
			}
		}
		else {
			if (notAboveQuit) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveQuit = false;
				aboveQuit = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(quitListener, quit);

	//以下为各个关卡设置点击事件,可在点击事件内设置场景转换动画
	auto level1Click = EventListenerMouse::create();
	level1Click->onMouseDown = [](Event* event) {
		log("level one clicked");
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 108 && mouse->getCursorX() < 254 &&
			mouse->getCursorY() < -70 && mouse->getCursorY() > -202) {
			//获取当前时间作为随机数种子
			srand((unsigned int)time(nullptr));
			//生成范围为[1, 20]的随机数,20中随机动画
			int a = (rand() % 20) + 1;
			switch (a) {
			case 1:
				Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelOneScene::create()));
				break;
			case 2:
				Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelOneScene::create()));
				break;
			case 3:
				Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelOneScene::create()));
				break;
			case 4:
				Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelOneScene::create()));
				break;
			case 5:
				Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelOneScene::create()));
				break;
			case 6:
				Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelOneScene::create()));
				break;
			case 7:
				Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelOneScene::create()));
				break;
			case 8:
				Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelOneScene::create()));
				break;
			case 9:
				Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelOneScene::create()));
				break;
			case 10:
				Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelOneScene::create()));
				break;
			case 11:
				Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelOneScene::create()));
				break;
			case 12:
				Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelOneScene::create()));
				break;
			case 13:
				Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelOneScene::create()));
				break;
			case 14:
				Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelOneScene::create()));
				break;
			case 15:
				Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelOneScene::create()));
				break;
			case 16:
				Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelOneScene::create()));
				break;
			case 17:
				Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelOneScene::create()));
				break;
			case 18:
				Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelOneScene::create()));
				break;
			case 19:
				Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelOneScene::create()));
				break;
			case 20:
				Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelOneScene::create(), true));
				break;
			default:
				log("ERROR!");
				break;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level1Click, level1);

	//关卡2图片点击事件
	auto level2Click = EventListenerMouse::create();
	level2Click->onMouseDown = [&](Event* event) {
		log("level two clicked");
		log("level two clicked");
		if (level2Unlock) {
			EventMouse* mouse = static_cast<EventMouse*>(event);
			if (mouse->getCursorX() > 252 && mouse->getCursorX() < 396 &&
				mouse->getCursorY() > -286 && mouse->getCursorY() < -185) {
				//获取当前时间作为随机数种子
				srand((unsigned int)time(nullptr));
				//生成范围为[1, 20]的随机数,20中随机动画
				int a = (rand() % 20) + 1;
				switch (a) {
				case 1:
					Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelTwoScene::create()));
					break;
				case 2:
					Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelTwoScene::create()));
					break;
				case 3:
					Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelTwoScene::create()));
					break;
				case 4:
					Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelTwoScene::create()));
					break;
				case 5:
					Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelTwoScene::create()));
					break;
				case 6:
					Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelTwoScene::create()));
					break;
				case 7:
					Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelTwoScene::create()));
					break;
				case 8:
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelTwoScene::create()));
					break;
				case 9:
					Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelTwoScene::create()));
					break;
				case 10:
					Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelTwoScene::create()));
					break;
				case 11:
					Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelTwoScene::create()));
					break;
				case 12:
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelTwoScene::create()));
					break;
				case 13:
					Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelTwoScene::create()));
					break;
				case 14:
					Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelTwoScene::create()));
					break;
				case 15:
					Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelTwoScene::create()));
					break;
				case 16:
					Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelTwoScene::create()));
					break;
				case 17:
					Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelTwoScene::create()));
					break;
				case 18:
					Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelTwoScene::create()));
					break;
				case 19:
					Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelTwoScene::create()));
					break;
				case 20:
					Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelTwoScene::create(), true));
					break;
				default:
					log("ERROR!");
					break;
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level2Click, level2);

	//关卡3点击事件
	auto level3Click = EventListenerMouse::create();
	level3Click->onMouseDown = [&](Event* event) {
		log("level three clicked");
		log("level three clicked");
		log("level three clicked");
		if (level3Unlock) {
			EventMouse* mouse = static_cast<EventMouse*>(event);
			if (mouse->getCursorX() > 398 && mouse->getCursorX() < 542 &&
				mouse->getCursorY() > -350 && mouse->getCursorY() < -240) {
				//获取当前时间作为随机数种子
				srand((unsigned int)time(nullptr));
				//生成范围为[1, 20]的随机数,20中随机动画
				int a = (rand() % 20) + 1;
				switch (a) {
				case 1:
					Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelThreeScene::create()));
					break;
				case 2:
					Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelThreeScene::create()));
					break;
				case 3:
					Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelThreeScene::create()));
					break;
				case 4:
					Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelThreeScene::create()));
					break;
				case 5:
					Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelThreeScene::create()));
					break;
				case 6:
					Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelThreeScene::create()));
					break;
				case 7:
					Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelThreeScene::create()));
					break;
				case 8:
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelThreeScene::create()));
					break;
				case 9:
					Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelThreeScene::create()));
					break;
				case 10:
					Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelThreeScene::create()));
					break;
				case 11:
					Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelThreeScene::create()));
					break;
				case 12:
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelThreeScene::create()));
					break;
				case 13:
					Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelThreeScene::create()));
					break;
				case 14:
					Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelThreeScene::create()));
					break;
				case 15:
					Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelThreeScene::create()));
					break;
				case 16:
					Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelThreeScene::create()));
					break;
				case 17:
					Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelThreeScene::create()));
					break;
				case 18:
					Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelThreeScene::create()));
					break;
				case 19:
					Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelThreeScene::create()));
					break;
				case 20:
					Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelThreeScene::create(), true));
					break;
				default:
					log("ERROR!");
					break;
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level3Click, level5);

	//关卡4点击事件
	auto level4Click = EventListenerMouse::create();
	level4Click->onMouseDown = [&](Event* event) {
		log("level four clicked");
		log("level four clicked");
		log("level four clicked");
		log("level four clicked");
		if (level4Unlock) {
			EventMouse* mouse = static_cast<EventMouse*>(event);
			if (mouse->getCursorX() > 547 && mouse->getCursorX() < 699 &&
				mouse->getCursorY() > -440 && mouse->getCursorY() < -322) {
				//获取当前时间作为随机数种子
				srand((unsigned int)time(nullptr));
				//生成范围为[1, 20]的随机数,20中随机动画
				int a = (rand() % 20) + 1;
				switch (a) {
				case 1:
					Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelFourScene::create()));
					break;
				case 2:
					Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelFourScene::create()));
					break;
				case 3:
					Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelFourScene::create()));
					break;
				case 4:
					Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelFourScene::create()));
					break;
				case 5:
					Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelFourScene::create()));
					break;
				case 6:
					Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelFourScene::create()));
					break;
				case 7:
					Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelFourScene::create()));
					break;
				case 8:
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelFourScene::create()));
					break;
				case 9:
					Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelFourScene::create()));
					break;
				case 10:
					Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelFourScene::create()));
					break;
				case 11:
					Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelFourScene::create()));
					break;
				case 12:
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelFourScene::create()));
					break;
				case 13:
					Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelFourScene::create()));
					break;
				case 14:
					Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelFourScene::create()));
					break;
				case 15:
					Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelFourScene::create()));
					break;
				case 16:
					Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelFourScene::create()));
					break;
				case 17:
					Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelFourScene::create()));
					break;
				case 18:
					Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelFourScene::create()));
					break;
				case 19:
					Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelFourScene::create()));
					break;
				case 20:
					Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelFourScene::create(), true));
					break;
				default:
					log("ERROR!");
					break;
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level4Click, level4);

	//关卡5点击事件
	auto level5Click = EventListenerMouse::create();
	level5Click->onMouseDown = [&](Event* event) {
		log("level five clicked");
		log("level five clicked");
		log("level five clicked");
		log("level five clicked");
		log("level five clicked");
		if (level5Unlock) {
			EventMouse* mouse = static_cast<EventMouse*>(event);
			if (mouse->getCursorX() > 396 && mouse->getCursorX() < 540 &&
				mouse->getCursorY() > -516 && mouse->getCursorY() < -418) {
				//获取当前时间作为随机数种子
				srand((unsigned int)time(nullptr));
				//生成范围为[1, 20]的随机数,20中随机动画
				int a = (rand() % 20) + 1;
				switch (a) {
				case 1:
					Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelFiveScene::create()));
					break;
				case 2:
					Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelFiveScene::create()));
					break;
				case 3:
					Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelFiveScene::create()));
					break;
				case 4:
					Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelFiveScene::create()));
					break;
				case 5:
					Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelFiveScene::create()));
					break;
				case 6:
					Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelFiveScene::create()));
					break;
				case 7:
					Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelFiveScene::create()));
					break;
				case 8:
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelFiveScene::create()));
					break;
				case 9:
					Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelFiveScene::create()));
					break;
				case 10:
					Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelFiveScene::create()));
					break;
				case 11:
					Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelFiveScene::create()));
					break;
				case 12:
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelFiveScene::create()));
					break;
				case 13:
					Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelFiveScene::create()));
					break;
				case 14:
					Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelFiveScene::create()));
					break;
				case 15:
					Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelFiveScene::create()));
					break;
				case 16:
					Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelFiveScene::create()));
					break;
				case 17:
					Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelFiveScene::create()));
					break;
				case 18:
					Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelFiveScene::create()));
					break;
				case 19:
					Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelFiveScene::create()));
					break;
				case 20:
					Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelFiveScene::create(), true));
					break;
				default:
					log("ERROR!");
					break;
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level5Click, level5);

	//关卡6点击事件
	auto level6Click = EventListenerMouse::create();
	level6Click->onMouseDown = [&](Event* event) {
		log("level six clicked");
		log("level six clicked");
		log("level six clicked");
		log("level six clicked");
		log("level six clicked");
		log("level six clicked");
		if (level6Unlock) {
			EventMouse* mouse = static_cast<EventMouse*>(event);
			if (mouse->getCursorX() < 391 && mouse->getCursorX() > 255 &&
				mouse->getCursorY() < -490 && mouse->getCursorY() > -592) {
				//获取当前时间作为随机数种子
				srand((unsigned int)time(nullptr));
				//生成范围为[1, 20]的随机数,20中随机动画
				int a = (rand() % 20) + 1;
				switch (a) {
				case 1:
					Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelSixScene::create()));
					break;
				case 2:
					Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelSixScene::create()));
					break;
				case 3:
					Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelSixScene::create()));
					break;
				case 4:
					Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelSixScene::create()));
					break;
				case 5:
					Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelSixScene::create()));
					break;
				case 6:
					Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelSixScene::create()));
					break;
				case 7:
					Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelSixScene::create()));
					break;
				case 8:
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelSixScene::create()));
					break;
				case 9:
					Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelSixScene::create()));
					break;
				case 10:
					Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelSixScene::create()));
					break;
				case 11:
					Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelSixScene::create()));
					break;
				case 12:
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelSixScene::create()));
					break;
				case 13:
					Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelSixScene::create()));
					break;
				case 14:
					Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelSixScene::create()));
					break;
				case 15:
					Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelSixScene::create()));
					break;
				case 16:
					Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelSixScene::create()));
					break;
				case 17:
					Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelSixScene::create()));
					break;
				case 18:
					Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelSixScene::create()));
					break;
				case 19:
					Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelSixScene::create()));
					break;
				case 20:
					Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelSixScene::create(), true));
					break;
				default:
					log("ERROR!");
					break;
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level6Click, level6);

	//关卡7点击事件
	auto level7Click = EventListenerMouse::create();
	level7Click->onMouseDown = [&](Event* event) {
		log("level seven clicked");
		log("level seven clicked");
		log("level seven clicked");
		log("level seven clicked");
		log("level seven clicked");
		log("level seven clicked");
		log("level seven clicked");
		if (level7Unlock) {
			EventMouse* mouse = static_cast<EventMouse*>(event);
			if (mouse->getCursorX() > 107 && mouse->getCursorX() < 253 &&
				mouse->getCursorY() > -685 && mouse->getCursorY() < -577) {
				//获取当前时间作为随机数种子
				srand((unsigned int)time(nullptr));
				//生成范围为[1, 20]的随机数,20中随机动画
				int a = (rand() % 20) + 1;
				switch (a) {
				case 1:
					Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelSevenScene::create()));
					break;
				case 2:
					Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelSevenScene::create()));
					break;
				case 3:
					Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelSevenScene::create()));
					break;
				case 4:
					Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelSevenScene::create()));
					break;
				case 5:
					Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelSevenScene::create()));
					break;
				case 6:
					Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelSevenScene::create()));
					break;
				case 7:
					Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelSevenScene::create()));
					break;
				case 8:
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelSevenScene::create()));
					break;
				case 9:
					Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelSevenScene::create()));
					break;
				case 10:
					Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelSevenScene::create()));
					break;
				case 11:
					Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelSevenScene::create()));
					break;
				case 12:
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelSevenScene::create()));
					break;
				case 13:
					Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelSevenScene::create()));
					break;
				case 14:
					Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelSevenScene::create()));
					break;
				case 15:
					Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelSevenScene::create()));
					break;
				case 16:
					Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelSevenScene::create()));
					break;
				case 17:
					Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelSevenScene::create()));
					break;
				case 18:
					Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelSevenScene::create()));
					break;
				case 19:
					Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelSevenScene::create()));
					break;
				case 20:
					Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelSevenScene::create(), true));
					break;
				default:
					log("ERROR!");
					break;
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level7Click, level7);

	//关卡8点击事件
	auto level8Click = EventListenerMouse::create();
	level8Click->onMouseDown = [&](Event* event) {
		log("level eight clicked");
		log("level eight clicked");
		log("level eight clicked");
		log("level eight clicked");
		log("level eight clicked");
		log("level eight clicked");
		log("level eight clicked");
		log("level eight clicked");
		log("level eight clicked");
		if (level8Unlock) {
			EventMouse* mouse = static_cast<EventMouse*>(event);
			if (mouse->getCursorX() > 137 && mouse->getCursorX() < 303 &&
				mouse->getCursorY() > -452 && mouse->getCursorY() < -336) {
				//获取当前时间作为随机数种子
				srand((unsigned int)time(nullptr));
				//生成范围为[1, 20]的随机数,20中随机动画
				int a = (rand() % 20) + 1;
				switch (a) {
				case 1:
					Director::getInstance()->replaceScene(TransitionProgressRadialCCW::create(0.5f, LevelEightScene::create()));
					break;
				case 2:
					Director::getInstance()->replaceScene(TransitionProgressRadialCW::create(0.5f, LevelEightScene::create()));
					break;
				case 3:
					Director::getInstance()->replaceScene(TransitionProgressHorizontal::create(0.5f, LevelEightScene::create()));
					break;
				case 4:
					Director::getInstance()->replaceScene(TransitionProgressVertical::create(0.5f, LevelEightScene::create()));
					break;
				case 5:
					Director::getInstance()->replaceScene(TransitionProgressInOut::create(0.5f, LevelEightScene::create()));
					break;
				case 6:
					Director::getInstance()->replaceScene(TransitionProgressOutIn::create(0.5f, LevelEightScene::create()));
					break;
				case 7:
					Director::getInstance()->replaceScene(TransitionFadeTR::create(0.5f, LevelEightScene::create()));
					break;
				case 8:
					Director::getInstance()->replaceScene(TransitionFadeBL::create(0.5f, LevelEightScene::create()));
					break;
				case 9:
					Director::getInstance()->replaceScene(TransitionFadeUp::create(0.5f, LevelEightScene::create()));
					break;
				case 10:
					Director::getInstance()->replaceScene(TransitionFadeDown::create(0.5f, LevelEightScene::create()));
					break;
				case 11:
					Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, LevelEightScene::create()));
					break;
				case 12:
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.5f, LevelEightScene::create()));
					break;
				case 13:
					Director::getInstance()->replaceScene(TransitionMoveInR::create(0.5f, LevelEightScene::create()));
					break;
				case 14:
					Director::getInstance()->replaceScene(TransitionMoveInT::create(0.5f, LevelEightScene::create()));
					break;
				case 15:
					Director::getInstance()->replaceScene(TransitionMoveInB::create(0.5f, LevelEightScene::create()));
					break;
				case 16:
					Director::getInstance()->replaceScene(TransitionSlideInB::create(0.5f, LevelEightScene::create()));
					break;
				case 17:
					Director::getInstance()->replaceScene(TransitionSlideInL::create(0.5f, LevelEightScene::create()));
					break;
				case 18:
					Director::getInstance()->replaceScene(TransitionSlideInR::create(0.5f, LevelEightScene::create()));
					break;
				case 19:
					Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5f, LevelEightScene::create()));
					break;
				case 20:
					Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5f, LevelEightScene::create(), true));
					break;
				default:
					log("ERROR!");
					break;
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(level8Click, level8);

	//退出按钮点击事件
	auto quitClick = EventListenerMouse::create();
	quitClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 747 && mouse->getCursorX() < 957 &&
			mouse->getCursorY() > -629 && mouse->getCursorY() < -575) {
			Director::getInstance()->end();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(quitClick, quit);


	return true;
}