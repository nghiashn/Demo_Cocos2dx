#include "LoadingScene.h"
#include <cocos\ui\UILoadingBar.h>
#include "GameMenuScene.h"
#include "Definition.h"

USING_NS_CC;

Scene* LoadingScene::createScene()
{
	auto scene = cocos2d::Scene::create();

	auto layer = LoadingScene::create();
	
	scene->addChild(layer);

	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Loading bar
	auto loadingbar = ui::LoadingBar::create("Img/LoadingBar.png");
	loadingbar->setScaleX(1.5);
	loadingbar->setPosition(Vec2(visibleSize.width * 0.6 + origin.x, visibleSize.height * 0.6 + origin.y));
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT); // huong chay
	loadingbar->setPercent(0);

	this->addChild(loadingbar);
	this->schedule([=](float delta)
		{
			float percent = loadingbar->getPercent();
			percent++;
			loadingbar->setPercent(percent);
			if (percent >= 100.0f)
			{
				this->unschedule("updateLoadingBar");
				this->scheduleOnce(CC_SCHEDULE_SELECTOR(LoadingScene::GoToGameMenuScene), DISPLAY_TIME_LOADING_SCENE);

			}
		},0.05f,"updateLoadingBar");
	
	//background
	auto background = Sprite::create("Img/background_Loadding.png");
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(background);

	return true;
}

void LoadingScene::GoToGameMenuScene(float dt)
{
	auto scene = GameMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}