//BulletLayer��ʵ���ӵ��Ĵ��������

#ifndef __BULLETLAYER_H__
#define __BULLETLAYER_H__
 
#include "cocos2d.h"

USING_NS_CC;

const int FLYVEIOCITY = 600;	//�ӵ������ٶ�

class BulletLayer :public cocos2d::Layer
{
public:
	virtual bool init();
	virtual void onEnter();
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event*event);
	
	void ShootBullet(float dt);		//�����ӵ��ĺ���
	void removeBullet(Node* pNode);		//�����Ƴ�������Ļ��Χ���ӵ�
	
	CREATE_FUNC(BulletLayer);
public:
	Vector<Sprite*> vecBullet;		//�ӵ�����
	SpriteBatchNode* bulletBatchNode;	//������Ⱦ�ڵ�
};
#endif