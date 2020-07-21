#pragma once
#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_

#include "cocos2d.h"
using namespace cocos2d;

#include "Hero.h"
#include"ActionSprite.h"

class GameLayer : public cocos2d::Layer
{
public:
    GameLayer();
    bool init();

    TMXTiledMap* mTileMap;

    void initTileMap();
    void initHero();

    Hero* mHero;

    //void ccTouchesBegan(CCSet* pTouches, CCEvent* pEvents);

//private :
    SpriteBatchNode* mActors;

    void update(float dt);

    void updatePosition(float dt);

    void setViewpointCenter(Point position);

    Vector<SpriteFrame*> mRobots;
    void initRobots();

    void reorderActors();
    void updateRobots(float dt);
};

#endif