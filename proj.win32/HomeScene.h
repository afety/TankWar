#ifndef __HOMESCENE_H__
#define __HOMESCENE_H__

#include "cocos2d.h"


//this scene will show levels which are locked or unlocked and setting options
class HomeScene : public cocos2d::Scene {
public:
	virtual bool init();

	CREATE_FUNC(HomeScene);
};


#endif // __HOMESCENE_H__