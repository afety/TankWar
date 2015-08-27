#ifndef __LEVELTHREESCENE_H__
#define __LEVELTHREESCENE_H__

#include "cocos2d.h"

class LevelThreeScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelThreeScene);
};


#endif // __LEVELTHREESCENE_H__