#ifndef __LEVELEIGHTSCENE_H__
#define __LEVELEIGHTSCENE_H__

#include "cocos2d.h"

class LevelEightScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelEightScene);
};



#endif // __LEVELEIGHTSCENE_H__