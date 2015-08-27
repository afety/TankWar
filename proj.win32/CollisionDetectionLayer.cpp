#include "proj.win32\CollisionDetectionLayer.h"
#include "proj.win32\Macros.h"

bool CollisionDetectionLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void CollisionDetectionLayer::onEnter()
{
	Layer::onEnter();
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(CollisionDetectionLayer::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
}

bool CollisionDetectionLayer::onContactBegin(PhysicsContact& contact)
{
	auto spA = (Sprite*)contact.getShapeA()->getBody()->getNode();
	auto spB = (Sprite*)contact.getShapeB()->getBody()->getNode();

	int tagA = spA->getTag();
	int tagB = spB->getTag();

	//检测坦克与子弹的碰撞
	if (tagA == BulletTag && tagB == TankTag || tagA == TankTag && tagB == BulletTag)
	{
		//检测到碰撞后进行的处理.
		log("Tank and Bullet Contacted!");
	}

	else if (tagA == BulletTag && tagB == TankTag || tagA == TankTag && tagB == BulletTag)
	{
		//检测到碰撞后进行的处理.
		log("Tank and Enemy Contacted!");
	}


	return true;
}