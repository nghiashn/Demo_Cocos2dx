#include"GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	mHudLayer = new HudLayer();
	this->addChild(mHudLayer, 1);
	
	this->schedule(CC_SCHEDULE_SELECTOR(GameScene::inputUpdate));

	return true;
}

void GameScene::inputUpdate(float dt)
{
	cocos2d::Vec2 velocity = mHudLayer->mJoystick->getVelocity();

	//if (velocity.x >= 0.4f || velocity.x <= -0.4f ||
	//	velocity.y >= 0.4f || velocity.y <= -0.4f)
	//{
	//	//
	//}
	//else
}