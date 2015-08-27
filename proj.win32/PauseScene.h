#ifndef __PAUSESCENE_H__
#define __PAUSESCENE_H__

#include "cocos2d.h"

class PauseScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(PauseScene);
};

#endif // __PAUSESCENE_H__