#ifndef __LEVELSLAYER_H__
#define __LEVELSLAYER_H__

#include "cocos2d.h"

class LevelsLayer : public cocos2d::Layer {
public:
	virtual bool init();

	CREATE_FUNC(LevelsLayer);

private:

	//��18����־�����ڱ�ʾ����Ƿ�λ�ڿɵ�������Ϸ����Լ�����������¼����ĵ�����
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