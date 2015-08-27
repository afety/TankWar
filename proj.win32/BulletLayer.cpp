#include "proj.win32\BulletLayer.h"
#include "proj.win32\Macros.h"

bool SpacePressed = false;

bool BulletLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	//创建BatchNode节点，减少创建大量子弹时的绘制次数
	bulletBatchNode = SpriteBatchNode::create("bullet48.png");
	this->addChild(bulletBatchNode);
	
	//每0.08S调用一次发射子弹函数
	this->schedule(schedule_selector(BulletLayer::ShootBullet), 0.15f);
	
	return true;
}

void BulletLayer::ShootBullet(float dt)
{
	//按下空格键才会添加子弹
	if (SpacePressed){

		auto visibleSize = Director::getInstance()->getVisibleSize();
		
		//从缓存中创建子弹
		auto bullet = Sprite::createWithTexture(bulletBatchNode->getTexture());

		//将创建好的子弹添加到BatchNode中进行批次渲染 
		bulletBatchNode->addChild(bullet);

		//将创建的子弹加入到容器
		vecBullet.pushBack(bullet);

		bullet->setTag(BulletTag);

		//设置子弹的发射位置，根据tank的位置来确定
		bullet->setPosition(visibleSize.width, visibleSize.height / 2);

		//子弹飞行距离也需要根据tank的位置来计算
		float flyLen = visibleSize.width;
		float flyDuration = flyLen / FLYVEIOCITY;

		
		auto bulletBody = PhysicsBody::createBox(bullet->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT);

		//设置掩码，不然OnContactBegin可能检测不到碰撞
		bulletBody->setContactTestBitmask(0xFFFFFFFF);
		
		//将物体绑定到子弹
		bullet->setPhysicsBody(bulletBody);

		//不受重力影响
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
	//这里的bullet是执行完actionFly动作的那个
	Sprite* bullet = (Sprite*)pNode;
	this->bulletBatchNode->removeChild(bullet, true);
	vecBullet.eraseObject(bullet);
}

//监听空格键
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