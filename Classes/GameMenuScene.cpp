#include"GameMenuScene.h"
#include"GameScene.h"

USING_NS_CC;

Scene* GameMenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameMenuScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameMenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//background
	auto background = Sprite::create("Img/background_Loadding.png");
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(background);

	//menuitem
	auto playItem = MenuItemImage::create("Img/playBtn.png", "Img/playBtnClick.png",
		CC_CALLBACK_1(GameMenuScene::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);

	return true;
}

void GameMenuScene::GoToGameScene(Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
}