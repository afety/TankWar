#ifndef TANK_H
#define TANK_H

#include "cocos2d.h"

USING_NS_CC;
//坦克升级
enum upgrade{
	upgradeNone,  //未升级
	upgradeSpeed,  //速度升级
	upgradeDefense,   //防御升级
	upgradeDamage   //攻击升级
};
//坦克方向
enum direction{
	up,  //向上
	down,	//向下
	left,   //向左
	right   //向右
};
//坦克类型

//坦克基类
class Tank : public cocos2d::Sprite{
private:
	//坦克方向
	enum direction dir;
	//坦克宽度，高度
	double width, height;
	//坦克位置
	Point pos;
public:
	//获取坦克方向
	virtual enum direction getDir() = 0;
	//获取坦克位置
	virtual Point getPos() = 0;
	//坦克移动
	virtual void move() = 0;
	//坦克射击
	virtual void fire() = 0;
};


class PlayerTank : public Tank{
private:
	//子弹类
	//BulletLayer bullet;
	//坦克升级状态
	enum upgrade tankUpgrade;
	//坦克方向
	enum direction dir;
	//坦克生命数，防御点数，速度，攻击点数
	int lives, defense, speed, damage;
	//坦克宽度和高度
	double width;
	double height;
	//坦克位置
	cocos2d::Point tankPos;

public:
	//自定义初始化
	virtual bool init();
	//自定义create
	static PlayerTank* create();
	//坦克移动
	virtual void move();
	//获取玩家坦克坐标
	Point getPos(){ return tankPos; }
	//获取坦克宽度，高度
	cocos2d::Size playerSize(){ return PlayerTank::getContentSize(); }
	//获取坦克方向
	enum direction getDir(){ return dir; }
	void keymove(EventKeyboard::KeyCode keyCode, Event* event);
	//坦克升级
	void speedUpgrade();
	void defenseUpgrade();
	void damageUpgrade();
	//坦克升级后图片改变
	void changeType(Event* event);
	//坦克开火
	void fire(){};
}; 

class EnermyTank : public PlayerTank{
private:
	//子弹类
	//BulletLayer bullet;
	//坦克升级状态
	enum upgrade tankUpgrade;
	//坦克方向
	enum direction dir;
	//坦克生命数，防御点数，速度，攻击点数
	int lives, defense, speed, damage;
	//坦克宽度和高度
	double width;
	double height;
	//坦克位置
	cocos2d::Point tankPos;

public:
	//自定义初始化
	virtual bool init(const char* imgName,Point spawnPos);
	//自定义create
	static EnermyTank* create(const char* imgName,Point spawnPos);
	//坦克移动
	virtual void move();
	//获取玩家坦克坐标
	Point getPos(){ return tankPos; }
	//获取坦克宽度，高度
	cocos2d::Size playerSize(){ return EnermyTank::getContentSize(); }
	//获取坦克方向
	enum direction getDir(){ return dir; }

};

#endif