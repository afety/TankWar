#ifndef __LEVELSEVENSCENE_H__
#define __LEVELSEVENSCENE_H__

#include "cocos2d.h"

class LevelSevenScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelSevenScene);
};



#endif // __LEVELSEVENSCENE_H__