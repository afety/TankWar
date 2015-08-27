#ifndef __COLLISIONDETECTIONLAYER_H__
#define __COLLISIONDETECTIONLAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class CollisionDetectionLayer :public cocos2d::Layer
{
public:
	virtual bool init();
	virtual void onEnter();
	virtual bool onContactBegin(PhysicsContact& contact);
	CREATE_FUNC(CollisionDetectionLayer);
};
#endif