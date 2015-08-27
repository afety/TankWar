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

/////////////////////ͼƬģ��������Ĵ���///////////////////////////////////////////////////////////////
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

/////////////////////��ͼ����///////////////////////////////////////////////////////////
//utils::captureScreen(CC_CALLBACK_2(����::capture, this), "capture.png");
//captureΪ�ص������������ڽ�ͼ���֮����ã�ʵ��������
//void capture(bool succeed, const std::string& outputFile);
//
//��capture�ص�����֮����if��succeed��������һ������ת����䣬ת������ͣ����
////////////////////////////////////////////////////////////////////////////////////////

USING_NS_CC;

bool PauseLayer::init() {

	if (!Layer::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//���cocos�����ļ������·��
	String string = FileUtils::getInstance()->getWritablePath().c_str();
	//���·��+������ͼ�õ�ȫ·����
	string.append("capture.png");
	//����ת��
	const char* hulala = string.getCString();

	//�ó�����ͼ����ģ�����鲢��Ϊ������ʵ�ֱ����黯
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

	//�����ͣ�˵��ı���
	auto showBackground = Sprite::create("Pause_bg.png");
	showBackground->setPosition(Vec2(visibleSize.width / 2 - 12, visibleSize.height / 2 + 30));
	this->addChild(showBackground);

	//��ӡ���ͣ��
	auto pause = Sprite::create("Pause_name.png");
	pause->setPosition(Vec2(495, 580));
	this->addChild(pause);

	//��ӡ��ؿ�ѡ��
	auto selectLevel = Sprite::create("Pause_select.png");
	selectLevel->setPosition(Vec2(495, 510));
	this->addChild(selectLevel);

	//��ӡ�������Ϸ��
	auto resume = Sprite::create("Pause_resume.png");
	resume->setPosition(Vec2(495, 451));
	this->addChild(resume);

	//��ӡ����¿�ʼ��
	auto restart = Sprite::create("Pause_restart.png");
	restart->setPosition(Vec2(495, 385));
	this->addChild(restart);

	//��ӡ��˳���
	auto quit = Sprite::create("Pause_quit.png");
	quit->setPosition(Vec2(495, 295));
	this->addChild(quit);

	//��ӹؿ�ѡ����ͣ�¼�
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

	//��ӷ�����Ϸ��ͣ�¼�
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

	//������¿�ʼ��ͣ�¼�
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

	//����˳���ͣ�¼�
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


	//��ӡ��ؿ�ѡ�񡰵���¼�
	auto selectClick = EventListenerMouse::create();
	selectClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -275 && mouse->getCursorY() < -241) {
			//��ȡ��ǰʱ����Ϊ���������
			srand((unsigned int)time(nullptr));
			//���ɷ�ΧΪ[1, 20]�������,20���������
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

	//��ӡ�������Ϸ������¼�
	auto resumeClick = EventListenerMouse::create();
	resumeClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -334 && mouse->getCursorY() < -300) {
			//��ջ�еĹؿ���������ջ�У�������Ϸ
			Director::getInstance()->popScene();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(resumeClick, resume);

	//��ӡ����¿�ʼ������¼�
	auto restartClick = EventListenerMouse::create();
	restartClick->onMouseDown = [](Event* event) {
		EventMouse* mouse = static_cast<EventMouse*>(event);
		if (mouse->getCursorX() > 428 && mouse->getCursorX() < 562 &&
			mouse->getCursorY() > -400 && mouse->getCursorY() < -366) {
			//�жϵ�ǰ�ؿ����������볡����ʼ
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

	//��ӡ��˳�������¼�
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