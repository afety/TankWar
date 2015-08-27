#ifndef __MACROS_H__
#define __MACROS_H__

#include "cocos2d.h"

//Sprite的Tag
const auto BulletTag = 100;
const auto TankTag = 101;
const auto EnemyTankTag = 102;


//全局变量，用于存储判断正在运行的场景，某关场景正在运行时以下相应的变量为false
//值在场景的onEnter()和onExit()中进行改变
static int whichLevel = 0;

#endif