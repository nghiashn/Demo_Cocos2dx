#pragma once
#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "cocos2d.h"

//using namespace cocos2d;

#include"SneakyButton.h"
#include"SneakyButtonSkinedBase.h"
#include"SneakyJoyStick.h"
#include"SneakyJoyStickSkinedBase.h"

class HudLayer : public cocos2d::Layer
{
public:
	HudLayer();
	~HudLayer();

	bool init();

	SneakyButton* mButtonA;
	SneakyJoystick* mJoystick;
};

#endif // !__HUD_LAYER_H__

