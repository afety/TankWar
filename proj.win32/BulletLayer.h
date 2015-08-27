//BulletLayer类实现子弹的创建与飞行

#ifndef __BULLETLAYER_H__
#define __BULLETLAYER_H__
 
#include "cocos2d.h"

USING_NS_CC;

const int FLYVEIOCITY = 600;	//子弹飞行速度

class BulletLayer :public cocos2d::Layer
{
public:
	virtual bool init();
	virtual void onEnter();
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event*event);
	
	void ShootBullet(float dt);		//发射子弹的函数
	void removeBullet(Node* pNode);		//用于移除超出屏幕范围的子弹
	
	CREATE_FUNC(BulletLayer);
public:
	Vector<Sprite*> vecBullet;		//子弹容器
	SpriteBatchNode* bulletBatchNode;	//批次渲染节点
};
#endif