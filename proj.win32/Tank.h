#ifndef TANK_H
#define TANK_H

#include "cocos2d.h"

USING_NS_CC;
//̹������
enum upgrade{
	upgradeNone,  //δ����
	upgradeSpeed,  //�ٶ�����
	upgradeDefense,   //��������
	upgradeDamage   //��������
};
//̹�˷���
enum direction{
	up,  //����
	down,	//����
	left,   //����
	right   //����
};
//̹������

//̹�˻���
class Tank : public cocos2d::Sprite{
private:
	//̹�˷���
	enum direction dir;
	//̹�˿�ȣ��߶�
	double width, height;
	//̹��λ��
	Point pos;
public:
	//��ȡ̹�˷���
	virtual enum direction getDir() = 0;
	//��ȡ̹��λ��
	virtual Point getPos() = 0;
	//̹���ƶ�
	virtual void move() = 0;
	//̹�����
	virtual void fire() = 0;
};


class PlayerTank : public Tank{
private:
	//�ӵ���
	//BulletLayer bullet;
	//̹������״̬
	enum upgrade tankUpgrade;
	//̹�˷���
	enum direction dir;
	//̹���������������������ٶȣ���������
	int lives, defense, speed, damage;
	//̹�˿�Ⱥ͸߶�
	double width;
	double height;
	//̹��λ��
	cocos2d::Point tankPos;

public:
	//�Զ����ʼ��
	virtual bool init();
	//�Զ���create
	static PlayerTank* create();
	//̹���ƶ�
	virtual void move();
	//��ȡ���̹������
	Point getPos(){ return tankPos; }
	//��ȡ̹�˿�ȣ��߶�
	cocos2d::Size playerSize(){ return PlayerTank::getContentSize(); }
	//��ȡ̹�˷���
	enum direction getDir(){ return dir; }
	void keymove(EventKeyboard::KeyCode keyCode, Event* event);
	//̹������
	void speedUpgrade();
	void defenseUpgrade();
	void damageUpgrade();
	//̹��������ͼƬ�ı�
	void changeType(Event* event);
	//̹�˿���
	void fire(){};
}; 

class EnermyTank : public PlayerTank{
private:
	//�ӵ���
	//BulletLayer bullet;
	//̹������״̬
	enum upgrade tankUpgrade;
	//̹�˷���
	enum direction dir;
	//̹���������������������ٶȣ���������
	int lives, defense, speed, damage;
	//̹�˿�Ⱥ͸߶�
	double width;
	double height;
	//̹��λ��
	cocos2d::Point tankPos;

public:
	//�Զ����ʼ��
	virtual bool init(const char* imgName,Point spawnPos);
	//�Զ���create
	static EnermyTank* create(const char* imgName,Point spawnPos);
	//̹���ƶ�
	virtual void move();
	//��ȡ���̹������
	Point getPos(){ return tankPos; }
	//��ȡ̹�˿�ȣ��߶�
	cocos2d::Size playerSize(){ return EnermyTank::getContentSize(); }
	//��ȡ̹�˷���
	enum direction getDir(){ return dir; }

};

#endif