#ifndef __LEVELSLAYER_H__
#define __LEVELSLAYER_H__

#include "cocos2d.h"

class LevelsLayer : public cocos2d::Layer {
public:
	virtual bool init();

	CREATE_FUNC(LevelsLayer);

private:

	//这18个标志量用于表示鼠标是否位于可点击精灵上方，以减少鼠标悬浮事件消耗的性能
	bool aboveLevelOne = true;
	bool aboveLevelTwo = true;
	bool aboveLevelThree = true;
	bool aboveLevelFour = true;
	bool aboveLevelFive = true;
	bool aboveLevelSix = true;
	bool aboveLevelSeven = true;
	bool aboveLevelEight = true;
	bool aboveQuit = true;
	bool notAboveLevelOne = false;
	bool notAboveLevelTwo = false;
	bool notAboveLevelThree = false;
	bool notAboveLevelFour = false;
	bool notAboveLevelFive = false;
	bool notAboveLevelSix = false;
	bool notAboveLevelSeven = false;
	bool notAboveLevelEight = false;
	bool notAboveQuit = false;
};


#endif // __LEVELSLAYER_H__