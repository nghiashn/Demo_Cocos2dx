#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

#include "HudLayer.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void inputUpdate(float dt);

	CREATE_FUNC(GameScene);

private:
	HudLayer* mHudLayer;

};

#endif // !__GAME_SCENE_H__
