#include "proj.win32\BulletLayer.h"
#include "proj.win32\Macros.h"

bool SpacePressed = false;

bool BulletLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	//����BatchNode�ڵ㣬���ٴ��������ӵ�ʱ�Ļ��ƴ���
	bulletBatchNode = SpriteBatchNode::create("bullet48.png");
	this->addChild(bulletBatchNode);
	
	//ÿ0.08S����һ�η����ӵ�����
	this->schedule(schedule_selector(BulletLayer::ShootBullet), 0.15f);
	
	return true;
}

void BulletLayer::ShootBullet(float dt)
{
	//���¿ո���Ż�����ӵ�
	if (SpacePressed){

		auto visibleSize = Director::getInstance()->getVisibleSize();
		
		//�ӻ����д����ӵ�
		auto bullet = Sprite::createWithTexture(bulletBatchNode->getTexture());

		//�������õ��ӵ���ӵ�BatchNode�н���������Ⱦ 
		bulletBatchNode->addChild(bullet);

		//���������ӵ����뵽����
		vecBullet.pushBack(bullet);

		bullet->setTag(BulletTag);

		//�����ӵ��ķ���λ�ã�����tank��λ����ȷ��
		bullet->setPosition(visibleSize.width, visibleSize.height / 2);

		//�ӵ����о���Ҳ��Ҫ����tank��λ��������
		float flyLen = visibleSize.width;
		float flyDuration = flyLen / FLYVEIOCITY;

		
		auto bulletBody = PhysicsBody::createBox(bullet->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);

		//�������룬��ȻOnContactBegin���ܼ�ⲻ����ײ
		bulletBody->setContactTestBitmask(0xFFFFFFFF);
		
		//������󶨵��ӵ�
		bullet->setPhysicsBody(bulletBody);

		//��������Ӱ��
		bulletBody->setGravityEnable(false);

		auto actionFly = MoveTo::create(flyDuration, Point(-10, visibleSize.height / 2));
		auto actionFlyDone = CallFuncN::create(CC_CALLBACK_1(BulletLayer::removeBullet, this));

		Sequence* sequence = Sequence::create(actionFly, actionFlyDone, NULL);

		bullet->runAction(sequence);
	}
}

void BulletLayer::removeBullet(Node* pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	//�����bullet��ִ����actionFly�������Ǹ�
	Sprite* bullet = (Sprite*)pNode;
	this->bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}

//�����ո��
void BulletLayer::onEnter()
{
	Layer::onEnter();
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = CC_CALLBACK_2(BulletLayer::onKeyPressed, this);
	keyBoardListener->onKeyReleased = CC_CALLBACK_2(BulletLayer::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
}

void BulletLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		SpacePressed = true;
	}
}

void BulletLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event*event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		SpacePressed = false;
	}
}