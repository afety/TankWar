#ifndef __SPLASHLAYER_H__
#define __SPLASHLAYER_H__

#include "cocos2d.h"

class SplashLayer : public cocos2d::Layer {
public:
	virtual bool init();

	CREATE_FUNC(SplashLayer);

private:

	//这4个标志量用于表示鼠标是否位于可点击精灵上方，以减少鼠标悬浮事件消耗的性能
	bool aboveStart = true;
	bool aboveQuit = true;
	bool notAboveStart = false;
	bool notAboveQuit = false;
};


#endif // __SPLASHLAYER_H__