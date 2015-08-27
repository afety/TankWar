#ifndef __LEVELTWOSCENE_H__
#define __LEVELTWOSCENE_H__

#include "cocos2d.h"

class LevelTwoScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelTwoScene);
};


#endif // LEVELTWOSCENE_H__