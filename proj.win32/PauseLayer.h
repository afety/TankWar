#ifndef __PAUSELAYER_H__
#define __PAUSELAYER_H__

#include "cocos2d.h"

class PauseLayer : public cocos2d::Layer {
public:
	virtual bool init();

	CREATE_FUNC(PauseLayer);

private:

	//这8个标志量用于表示鼠标是否位于可点击精灵上方，以减少鼠标悬浮事件消耗的性能
	bool aboveSelection = true;
	bool aboveResume = true;
	bool aboveRestart = true;
	bool aboveQuit = true;
	bool notAboveSelection = false;
	bool notAboveResume = false;
	bool notAboveRestart = false;
	bool notAboveQuit = false;
};


#endif // __PAUSELAYER_H__