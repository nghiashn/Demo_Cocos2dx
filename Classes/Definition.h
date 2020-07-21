#pragma once
#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#define DISPLAY_TIME_LOADING_SCENE 1.5
#define TRANSITION_TIME 3

#define SCREEN (CCDirector::sharedDirector()->getWinSize())
#define CENTER (ccp(SCREEN.width/2, SCREEN.height/2))
//#define CURTIME CACurrentMediaTime()
//#define CURTIME 1
//#define CURTIME time(NULL)

inline int random_range(int low, int high)
{
	return ((rand() % (high - low + 1)) + low);
}

inline float frandom_range(float low, float high, float precision)
{
	float tmp = 1.0f / precision;
	return random_range(low * tmp, high * tmp) * precision;
}

inline float GetMAX(float x, float y)
{
	return (x > y ? x : y);
}

inline float GetMIN(float x, float y)
{
	return (x < y ? x : y);
}

enum ActionState
{
	kActionStateNone = 0,
	kActionStateIdle,
	kActionStateAttack,
	kActionStateWalk,
	kActionStateHurt,
	kActionStateKnockedOut
};

typedef struct _BoundingBox
{
	cocos2d::Rect actual;
	cocos2d::Rect original;
}BoundingBox;

#define ACTION_SPRITE_TAG 100

#endif // !__DEFINITION_H__
