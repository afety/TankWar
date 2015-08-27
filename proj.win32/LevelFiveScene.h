#ifndef __LEVELFIVESCENE_H__
#define __LEVELFIVESCENE_H__

#include "cocos2d.h"

class LevelFiveScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelFiveScene);
};


#endif // __LEVELFIVESCENE_H__