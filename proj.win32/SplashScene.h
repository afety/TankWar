#ifndef __SPLASHSCENE_H__
#define __SPLASHSCENE_H__

#include "cocos2d.h"

//this scene will be shown for 2 seconds when the app first starts.
class SplashScene : public cocos2d::Scene {
public:
	virtual bool init();

	//进入和退出场景时所要执行的方法
	virtual void onEnter();
	virtual void onExit();

	CREATE_FUNC(SplashScene);
};


#endif // __SPLASHSCENE_H__