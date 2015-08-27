#ifndef __LEVELSIXSCENE_H__
#define __LEVELSIXSCENE_H__

#include "cocos2d.h"


class LevelSixScene : public cocos2d::Scene {
public:
	virtual bool init();

	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(LevelSixScene);
};



#endif // __LEVELSIXSCENE_H__