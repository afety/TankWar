#include "proj.win32\PauseLayer.h"
#include "proj.win32\HomeScene.h"
#include "proj.win32\Macros.h"
#include "proj.win32\LevelOneScene.h"
#include "proj.win32\LevelTwoScene.h"
#include "proj.win32\LevelThreeScene.h"
#include "proj.win32\LevelFourScene.h"
#include "proj.win32\LevelFiveScene.h"
#include "proj.win32\LevelSixScene.h"
#include "proj.win32\LevelSevenScene.h"
#include "proj.win32\LevelEightScene.h"

#include <cstdlib>

/////////////////////图片模糊处理核心代码///////////////////////////////////////////////////////////////
//GLchar * fragSource = (GLchar*)String::createWithContentsOfFile(
//	FileUtils::getInstance()->
//	fullPathForFilename("example_Blur.fsh").c_str())->
//	getCString();
//auto program = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource);
//auto glProgramState = GLProgramState::getOrCreateWithGLProgram(program);
//sprite->setGLProgramState(glProgramState);
//auto size = sprite->getTexture()->getContentSizeInPixels();
//sprite->getGLProgramState()->setUniformVec2("resolution", size);
//sprite->getGLProgramState()->setUniformFloat("blurRadius", 10.0f);
//sprite->getGLProgramState()->setUniformFloat("sampleNum", 3.2f);
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////截图函数///////////////////////////////////////////////////////////
//utils::captureScreen(CC_CALLBACK_2(类名::capture, this), "capture.png");
//capture为回调函数，用于在截图完成之后调用，实现在类内
//void capture(bool succeed, const std::string& outputFile);
//
//在capture回调函数之内用if（succeed）来包含一个场景转换语句，转换到暂停场景
////////////////////////////////////////////////////////////////////////////////////////

USING_NS_CC;

bool PauseLayer::init() {

	if (!Layer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//获得cocos生成文件的输出路径
	String string = FileUtils::getInstance()->getWritablePath().c_str();
	//输出路径+场景截图得到全路径名
	string.append("capture.png");
	//类型转化
	const char* hulala = string.getCString();

	//用场景截图生成模糊精灵并设为背景，实现背景虚化
	auto sprite = Sprite::create(hulala);
	GLchar * fragSource = (GLchar*)String::createWithContentsOfFile(
		FileUtils::getInstance()->
		fullPathForFilename("example_Blur.fsh").c_str())->
		getCString();
	auto program = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, fragSource);
	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(program);
	sprite->setGLProgramState(glProgramState);
	auto size = sprite->getTexture()->getContentSizeInPixels();
	sprite->getGLProgramState()->setUniformVec2("resolution", size);
	sprite->getGLProgramState()->setUniformFloat("blurRadius", 10.0f);
	sprite->getGLProgramState()->setUniformFloat("sampleNum", 3.2f);
	sprite->setPosition(Vec2(512, 384));
	this->addChild(sprite);

	//添加暂停菜单的背景
	auto showBackground = Sprite::create("Pause_bg.png");
	showBackground->setPosition(Vec2(visibleSize.width / 2 - 12, visibleSize.height / 2 + 30));
	this->addChild(showBackground);

	//添加“暂停”
	auto pause = Sprite::create("Pause_name.png");
	pause->setPosition(Vec2(495, 580));
	this->addChild(pause);

	//添加“关卡选择”
	auto selectLevel = Sprite::create("Pause_select.png");
	selectLevel->setPosition(Vec2(495, 510));
	this->addChild(selectLevel);

	//添加”返回游戏“
	auto resume = Sprite::create("Pause_resume.png");
	resume->setPosition(Vec2(495, 451));
	this->addChild(resume);

	//添加”重新开始“
	auto restart = Sprite::create("Pause_restart.png");
	restart->setPosition(Vec2(495, 385));
	this->addChild(restart);

	//添加”退出“
	auto quit = Sprite::create("Pause_quit.png");
	quit->setPosition(Vec2(495, 295));
	this->addChild(quit);

	//添加关卡选择悬停事件
	auto selectMove = EventListenerMouse::create();
	selectMove->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -275 && mouse->getCursorY() < -241) {
			if (aboveSelection) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveSelection = false;
				notAboveSelection = true;
			}
		}
		else {
			if (notAboveSelection) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveSelection = false;
				aboveSelection = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(selectMove, selectLevel);

	//添加返回游戏悬停事件
	auto resumeMove = EventListenerMouse::create();
	resumeMove->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -334 && mouse->getCursorY() < -300) {
			if (aboveResume) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveResume = false;
				notAboveResume = true;
			}
		}
		else {
			if (notAboveResume) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveResume = false;
				aboveResume = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(resumeMove, resume);

	//添加重新开始悬停事件
	auto restartMove = EventListenerMouse::create();
	restartMove->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -400 && mouse->getCursorY() < -366) {
			if (aboveRestart) {
				auto scale = ScaleTo::create(0.1f, 1.2f);
				sprite->runAction(scale);
				aboveRestart = false;
				notAboveRestart = true;
			}
		}
		else {
			if (notAboveRestart) {
				auto scaleBack = ScaleTo::create(0.1f, 1);
				sprite->runAction(scaleBack);
				notAboveRestart = false;
				aboveRestart = true;
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(restartMove, restart);

	//添加退出悬停事件
	auto quitMove = EventListenerMouse::create();
	quitMove->onMouseMove = [=](Event* event) {
		Sprite* sprite = static_cast<Sprite*>(event->getCurrentTarget());
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 459 && mouse->getCursorX() < 534 &&
			mouse->getCursorY() > -494 && mouse->getCursorY() < -452) {
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
	_eventDispatcher->addEventListenerWithSceneGraphPriority(quitMove, quit);


	//添加”关卡选择“点击事件
	auto selectClick = EventListenerMouse::create();
	selectClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -275 && mouse->getCursorY() < -241) {
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
	_eventDispatcher->addEventListenerWithSceneGraphPriority(selectClick, selectLevel);

	//添加“返回游戏”点击事件
	auto resumeClick = EventListenerMouse::create();
	resumeClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -334 && mouse->getCursorY() < -300) {
			//将栈中的关卡场景弹出栈中，继续游戏
			Director::getInstance()->popScene();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(resumeClick, resume);

	//添加“重新开始”点击事件
	auto restartClick = EventListenerMouse::create();
	restartClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -400 && mouse->getCursorY() < -366) {
			//判断当前关卡并重新载入场景开始
			if (whichLevel == 1) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelOneScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
			else if (whichLevel == 2) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelTwoScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
			else if (whichLevel == 3) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelThreeScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
			else if (whichLevel == 4) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelFourScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
			else if (whichLevel == 5) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelFiveScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
			else if (whichLevel == 6) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelSixScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
			else if (whichLevel == 7) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelSevenScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
			else if (whichLevel == 8) {
				auto transitionFade = TransitionCrossFade::create(0.1f, LevelEightScene::create());
				Director::getInstance()->replaceScene(transitionFade);
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(restartClick, restart);

	//添加“退出”点击事件
	auto quitClick = EventListenerMouse::create();
	quitClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 459 && mouse->getCursorX() < 534 &&
			mouse->getCursorY() > -494 && mouse->getCursorY() < -452) {
			Director::getInstance()->end();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(quitClick, quit);


	return true;
}