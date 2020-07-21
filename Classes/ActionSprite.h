#pragma once
#ifndef __ACTION_SPRITE_H__
#define __ACTION_SPRITE_H__

#include"cocos2d.h"
#include"Definition.h"

class ActionSprite : public cocos2d::Sprite
{
public:
	ActionSprite();
	~ActionSprite();

	virtual bool init();

	void idle();
	void attack();
	void hurtWithDamage(float damage);
	void knockout();
	void walkWithDirection(cocos2d::Point direction);

	virtual void update(float dt);

protected:
	cocos2d::Action* mIdleAction;
	cocos2d::Action* mAttackAction;
	cocos2d::Action* mWalkAction;
	cocos2d::Action* mHurtAction;
	cocos2d::Action* mKnockOutAction;

	ActionState mActionState;

	float mWalkSpeed;
	float mHitPoints;
	float mDamage;

	cocos2d::Point mVelocity;
	cocos2d::Point mDesiredPosition;

	float mCenterToSide;
	float mCenterToBottom;

	BoundingBox mHitBox;
	BoundingBox mAttackBox;

	BoundingBox createBoudingBoxWithOrigin(cocos2d::Point origin, cocos2d::Size size);

	void transformBoxes();
	void setPosition(const cocos2d::Point& pos);
};

#endif // !__ACTION_SPRITE_H__
