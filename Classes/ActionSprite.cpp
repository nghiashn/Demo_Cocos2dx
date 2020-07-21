#include"ActionSprite.h"
#include"Definition.h"

ActionSprite::ActionSprite()
{
	cocos2d::SpriteBatchNode::create("Img/pd_sprites.png");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Img/pd_sprites.plist");

	auto heroIdle = Sprite::createWithSpriteFrameName("hero_idle_00.png");

	mHitBox.actual = cocos2d::Rect::ZERO;
	mHitBox.original = cocos2d::Rect::ZERO;
	mAttackBox.actual = cocos2d::Rect::ZERO;
	mAttackBox.actual = cocos2d::Rect::ZERO;

	init();
}
ActionSprite::~ActionSprite()
{

}
bool ActionSprite::init()
{
	this->setTag(ACTION_SPRITE_TAG);
	cocos2d::Sprite::init();

	return true;
}

void ActionSprite::idle()
{
	if (mActionState != kActionStateIdle)
	{
		this->stopAllActions();
		this->runAction(mIdleAction);
		mActionState = kActionStateIdle;
		mVelocity = cocos2d::Point::ZERO;
	}
}

void ActionSprite::attack()
{
	if (mActionState == kActionStateIdle ||
		mActionState == kActionStateAttack ||
		mActionState == kActionStateWalk)
	{
		this->stopAllActions();
		this->runAction(mAttackAction);
		mActionState = kActionStateAttack;
	}
}

void ActionSprite::hurtWithDamage(float damage)
{
	if (mActionState != kActionStateKnockedOut)
	{
		this->stopAllActions();
		this->runAction(mHurtAction);
		mActionState = kActionStateHurt;
		mHitPoints -= damage;

		if (mHitPoints <= 0.0f)
		{
			this->knockout();
		}
	}
}

void ActionSprite::knockout()
{
	this->stopAllActions();
	this->runAction(mKnockOutAction);
	mHitPoints = 0.0f;
	mActionState = kActionStateKnockedOut;
}

void ActionSprite::walkWithDirection(cocos2d::Point direction)
{
	if (mActionState == kActionStateIdle)
	{
		this->stopAllActions();
		this->runAction(mWalkAction);
		mActionState = kActionStateWalk;
	}
	if (mActionState == kActionStateWalk)
	{
		mVelocity = cocos2d::Point(direction.x * mWalkSpeed,
			direction.y * mWalkSpeed);
	}
	if (mVelocity.x >= 0)
	{
		this->setFlippedX(false);
	}
	else
	{
		this->setFlippedX(true);
	}
}

void ActionSprite::update(float dt)
{
	if (mActionState == kActionStateWalk)
	{
		cocos2d::Point pt = mVelocity * dt;
		mDesiredPosition = this->getPosition() + pt;		
	}
	cocos2d::Sprite::update(dt);
}

BoundingBox ActionSprite::createBoudingBoxWithOrigin(cocos2d::Point origin, cocos2d::Size size)
{
	BoundingBox bBox;
	bBox.original.origin = origin;
	bBox.original.size = size;
	bBox.actual.origin = this->getPosition() + 
		cocos2d::Point(bBox.original.origin.x,bBox.original.origin.y);

	bBox.actual.size = size;

	return bBox;
}

void ActionSprite::transformBoxes()
{
	float xfactor = (this->isFlippedX() ? -1 : 1);
	float xfactor2 = (this->isFlippedX() ? 1 : 0);
	float yfactor = (this->isFlippedY() ? -1 : 1);
	float yfactor2 = (this->isFlippedY() ? -1 : 0);

	mHitBox.actual.origin = this->getPosition() +
		cocos2d::Point(mHitBox.original.origin.x * xfactor - mHitBox.original.size.width * xfactor2,
			mHitBox.original.origin.y * yfactor - mHitBox.original.size.height * yfactor2);
	
	mHitBox.actual.size = cocos2d::Size(mHitBox.original.size.width,
		mHitBox.original.size.height);

	mHitBox.actual.origin = this->getPosition() +
		cocos2d::Point(mAttackBox.original.origin.x * xfactor -
			mAttackBox.original.size.width * xfactor2,
			mAttackBox.original.origin.y * yfactor -
			mAttackBox.original.size.height * yfactor2);

	mAttackBox.actual.size = cocos2d::Size(mAttackBox.original.size.width,
		mAttackBox.original.size.height);
}
void ActionSprite::setPosition(const cocos2d::Point& pos)
{
	cocos2d::Sprite::setPosition(pos);
	this->transformBoxes();
}