#pragma once
#ifndef __GAME_MENU_SCENE_H__
#define __GAME_MENU_SCENE_H__

#include"cocos2d.h"

class GameMenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	
	void GoToGameScene(cocos2d::Ref* sender);

	CREATE_FUNC(GameMenuScene);
private:

};

#endif // !__GAME_MENU_SCENE_H__
