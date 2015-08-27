#ifndef __LEVELFOURSCENE_H__
#define __LEVELFOURSCENE_H__

#include "cocos2d.h"

class LevelFourScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelFourScene);
};


#endif // __LEVELFOURSCENE_H__