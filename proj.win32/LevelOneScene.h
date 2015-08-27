#ifndef __LEVELONESCENE_H__
#define __LEVELONESCENE_H__

#include "cocos2d.h"

class LevelOneScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelOneScene);
};


#endif // __LEVELONESCENE_H__