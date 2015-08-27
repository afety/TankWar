#ifndef __PAUSELAYER_H__
#define __PAUSELAYER_H__

#include "cocos2d.h"

class PauseLayer : public cocos2d::Layer {
public:
	virtual bool init();

	CREATE_FUNC(PauseLayer);

private:

	//��8����־�����ڱ�ʾ����Ƿ�λ�ڿɵ�������Ϸ����Լ�����������¼����ĵ�����
	bool aboveSelection = true;
	bool aboveResume = true;
	bool aboveRestart = true;
	bool aboveQuit = true;
	bool notAboveSelection = false;
	bool notAboveResume = false;
	bool notAboveRestart = false;
	bool notAboveQuit = false;
};


#endif // __PAUSELAYER_H__