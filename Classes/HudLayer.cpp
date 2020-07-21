#include"HudLayer.h"

HudLayer::HudLayer()
{
	cocos2d::SpriteBatchNode* spriteNode = cocos2d::SpriteBatchNode::create("Img/UI.png");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Img/UI.plist");
	
	auto joystickBase = cocos2d::Sprite::createWithSpriteFrameName("JoyStick-base.png");
	auto joystickThumb = cocos2d::Sprite::createWithSpriteFrameName("JoyStick-thumb.png");
	joystickBase->setScale(3);
	joystickThumb->setScale(3);

	mJoystick = NULL;
	mJoystick = new SneakyJoystick();
	mJoystick->initWithRect(cocos2d::Rect::ZERO);
	mJoystick->setAutoCenter(true);
	mJoystick->setHasDeadzone(true);
	mJoystick->setDeadRadius(10);

	SneakyJoystickSkinnedBase* jstickSkin = new SneakyJoystickSkinnedBase();
	jstickSkin->autorelease();
	jstickSkin->init();
	jstickSkin->setBackgroundSprite(joystickBase);
	jstickSkin->setThumbSprite(joystickThumb);

	jstickSkin->setPosition(cocos2d::Vec2(200,200));
	jstickSkin->setJoystick(mJoystick);
	this->addChild(jstickSkin);


	init();
}

HudLayer::~HudLayer()
{

}

bool HudLayer::init()
{
	Layer::init();
	return true;
}
