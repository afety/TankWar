#ifndef __SPLASHLAYER_H__
#define __SPLASHLAYER_H__

#include "cocos2d.h"

class SplashLayer : public cocos2d::Layer {
public:
	virtual bool init();

	CREATE_FUNC(SplashLayer);

private:

	//��4����־�����ڱ�ʾ����Ƿ�λ�ڿɵ�������Ϸ����Լ�����������¼����ĵ�����
	bool aboveStart = true;
	bool aboveQuit = true;
	bool notAboveStart = false;
	bool notAboveQuit = false;
};


#endif // __SPLASHLAYER_H__