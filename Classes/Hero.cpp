#include "Hero.h"

Hero::Hero()
{
    cocos2d::SpriteBatchNode::create("Img/pd_sprites.png");
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Img/pd_sprites.plist");

    cocos2d::Sprite::createWithSpriteFrameName("hero_idle_00.png");
    this->retain();


    char str[64] = { 0 };
    cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;

    //Idle
    for (int i = 0; i < 6; ++i) {
        sprintf(str, "hero_idle_%02d.png", i);
        cocos2d::SpriteFrame* frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    /************************************************************************/
    /*                                                                      */
    /************************************************************************/
    cocos2d::Animation* idleAnimation = cocos2d::Animation::createWithSpriteFrames(animFrames, 1.0f / 12.0f);
    mIdleAction = cocos2d::RepeatForever::create(cocos2d::Animate::create(idleAnimation));
    mIdleAction->retain();

    //Attack
    //animFrames->removeAllObjects();
    animFrames.clear();
    for (int i = 0; i < 3; ++i) {
        sprintf(str, "hero_attack_00_%02d.png", i);
        cocos2d::SpriteFrame* frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    cocos2d::Animation* attackAnimation = cocos2d::Animation::createWithSpriteFrames(animFrames, 1.0f / 24.0f);
    mAttackAction = cocos2d::Sequence::create(
        cocos2d::Animate::create(attackAnimation),
        cocos2d::CallFunc::create(CC_CALLBACK_0(Hero::idle, this)));
    mAttackAction->retain();

    //Walk
    animFrames.clear();
    for (int i = 0; i < 8; ++i) {
        sprintf(str, "hero_walk_%02d.png", i);
        cocos2d::SpriteFrame* frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    cocos2d::Animation* walkAnimation = cocos2d::Animation::createWithSpriteFrames(animFrames, 1.0f / 12.0f);
    mWalkAction =
        cocos2d::RepeatForever::create(cocos2d::Animate::create(walkAnimation));
    mWalkAction->retain();

    //Hurt
    animFrames.clear();
    for (int i = 0; i < 3; ++i) {
        sprintf(str, "hero_hurt_%02d.png", i);
        cocos2d::SpriteFrame* frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    cocos2d::Animation* hurtAnimation = cocos2d::Animation::createWithSpriteFrames(animFrames, 1.0f / 12.0f);
    mHurtAction = cocos2d::Sequence::create(
        cocos2d::Animate::create(hurtAnimation),
        cocos2d::CallFunc::create(CC_CALLBACK_0(Hero::idle, this)));
    mHurtAction->retain();

    //Knocked out
    animFrames.clear();
    for (int i = 0; i < 5; ++i) {
        sprintf(str, "hero_knockout_%02d.png", i);
        cocos2d::SpriteFrame* frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        animFrames.pushBack(frame);
    }
    cocos2d::Animation* knockedOutAnimation = cocos2d::Animation::createWithSpriteFrames(animFrames, 1.0f / 12.0f);
    mKnockOutAction = cocos2d::Sequence::create(
        cocos2d::Animate::create(knockedOutAnimation),
        cocos2d::Blink::create(2.0f, 10.0f), NULL);
    mKnockOutAction->retain();

    mCenterToBottom = 39.0f;
    mCenterToSide = 29.0f;
    mHitPoints = 100.0f;
    mDamage = 20.0f;
    mWalkSpeed = 80.0f;

    mHitBox = createBoudingBoxWithOrigin(
        cocos2d::Point(-mCenterToSide, -mCenterToBottom),
        cocos2d::Size(mCenterToSide * 2, mCenterToBottom * 2));

    mAttackBox = createBoudingBoxWithOrigin(
        cocos2d::Point(mCenterToSide, -10), cocos2d::Size(20, 20));

    this->scheduleUpdate();

    init();
}

bool Hero::init()
{
    ActionSprite::init();

    return true;
}