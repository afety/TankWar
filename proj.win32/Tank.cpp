#include"Tank.h"

USING_NS_CC;



bool PlayerTank::init(){
	if (!Sprite::initWithFile("monster.jpg")){
		return false;
	}
	//进行部分精灵类的设置
	auto visiable = Director::getInstance()->getWinSize();
	setPosition(Vec2(visiable.width / 2, visiable.height / 2));
	return true;
}

PlayerTank* PlayerTank::create(){
	PlayerTank* playerTank = new PlayerTank();
	if (playerTank->init()){
		playerTank->autorelease();
	}
	else{
		delete playerTank;
		playerTank = NULL;
		return NULL;
	}	
	auto imgSize = playerTank->getContentSize();
	playerTank->width = imgSize.width;
	playerTank->height = imgSize.height;
	playerTank->tankPos = playerTank->getPosition();

	//坦克方向默认向上
	playerTank->dir = up;

	//坦克默认升级1
	playerTank->tankUpgrade = upgradeNone;
	//玩家坦克，防御力，攻击力，生命数初始化
	playerTank->defense = 3;
	playerTank->damage = 2;
	playerTank->speed = 2;
	playerTank->lives = 3;

	return playerTank;
}

void PlayerTank::move(){
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(PlayerTank::keymove,this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
}

void PlayerTank::keymove(EventKeyboard::KeyCode keyCode, Event* event){
	auto player = static_cast<PlayerTank*>(event->getCurrentTarget());
	auto actionUP = MoveBy::create(2.0F, Vec2(0,20));
	auto actionDOWN = MoveBy::create(2.0F, Vec2(0, -20));
	auto actionRIGHT = MoveBy::create(2.0F, Vec2(20, 0));
	auto actionLEFT = MoveBy::create(2.0F, Vec2(-20, 0));

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		player->runAction(actionUP);
		player->tankPos.y += 20;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		player->runAction(actionDOWN);
		player->tankPos.y -= 20;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		player->runAction(actionRIGHT);
		player->tankPos.x += 20;
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		player->runAction(actionLEFT);
		player->tankPos.x -= 20;
		break;

	}
}

void PlayerTank::speedUpgrade(){
	tankUpgrade = upgradeSpeed;
	speed += 3;
}

void PlayerTank::defenseUpgrade(){
	tankUpgrade = upgradeDefense;
	defense += 3;
}

void PlayerTank::damageUpgrade(){
	tankUpgrade = upgradeDamage;
	damage += 3;
}

void PlayerTank::changeType(Event* event){
	auto player = static_cast<PlayerTank*>(event->getCurrentTarget());
	CCTexture2D *textureSpeed = TextureCache::sharedTextureCache()->addImage("");
	CCTexture2D *textureDefense = TextureCache::sharedTextureCache()->addImage("");
	CCTexture2D *textureDamage = TextureCache::sharedTextureCache()->addImage("");
	switch (player->tankUpgrade){
	case upgradeSpeed:
		break;
	case upgradeDefense:
		break;
	case upgradeDamage:
		break;
	default:
		break;
	}
}


/*------------------EnermyTank---------------------*/
bool EnermyTank::init(const char* imgName,cocos2d::Point spawnPos){
	if (!Sprite::initWithFile(imgName)){
		return false;
	}
	setPosition(spawnPos);
	return true;
}

EnermyTank* EnermyTank::create(const char* imgName,Point spawnPos){
	EnermyTank *enermy = new EnermyTank();
	if (enermy->init(imgName,spawnPos)){
		enermy->autorelease();
	}
	else{
		delete enermy;
		enermy = NULL;
		return NULL;
	}
}