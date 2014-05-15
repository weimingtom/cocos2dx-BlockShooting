//
//  HelpScene.cpp
//  BrockShooting
//
//  Created by sakura on 2014/05/15.
//
//

#include "HelpScene.h"
#include "TopScene.h"
#include "Config.h"
#include "UserSettings.h"
#include "GHelper.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

HelpScene::~HelpScene()
{
}

HelpScene::HelpScene()
{
}

CCScene* HelpScene::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		HelpScene *layer = HelpScene::create();
		CC_BREAK_IF(! layer);

		scene->addChild(layer, 100, kTagLayer);
	} while (0);
	return scene;
}

bool HelpScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }

    if (!CCLayerColor::initWithColor( ccc4(0,0,0,0) )) {
        return false;
    }
    _visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    // BGM再生
    if (UserSettings::getMusicSetting() &&
        !SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MP3_BG, true);

    makeLabels();

    makeBackButton();

    setKeypadEnabled(true);

    return  true;
}

void HelpScene::makeLabels()
{

    //item説明タイトル
    CCLabelBMFont* title = CCLabelBMFont::create("Items", FONT_BLUE);
    title->setScale(0.7);
    title->setPosition( ccp(_visibleSize.width / 2, _visibleSize.height * 0.8));
    this->addChild(title);

    //青
    CCSprite* image1 = CCSprite::create(PNG_P_BLUE, CCRectMake(0, 0, 24, 24));
    image1->cocos2d::CCNode::setAnchorPoint(CCPointZero);
    image1->setPosition( ccp(_visibleSize.width / 3.5, _visibleSize.height * 0.7));
    this->addChild(image1);

    CCLabelBMFont* disc1 = CCLabelBMFont::create("Quick Ball", FONT_WHITE);
    disc1->setScale(0.5);
    disc1->setAnchorPoint(CCPointZero);
    disc1->setPosition( ccp(image1->getPositionX() + image1->getContentSize().width + 15,
                            image1->getPositionY() - image1->getContentSize().height / 2));
    this->addChild(disc1);

    //緑
    CCSprite* image2 = CCSprite::create(PNG_P_GREEN, CCRectMake(0, 0, 24, 24));
    image2->setAnchorPoint(CCPointZero);
    image2->setPosition( ccp(_visibleSize.width / 3.5, _visibleSize.height * 0.65));
    this->addChild(image2);

    CCLabelBMFont* disc2 = CCLabelBMFont::create("Long Bar", FONT_WHITE);
    disc2->setScale(0.5);
    disc2->setAnchorPoint(CCPointZero);
    disc2->setPosition( ccp(image2->getPositionX() + image2->getContentSize().width + 15,
                            image2->getPositionY() - image2->getContentSize().height / 2));
    this->addChild(disc2);

    //赤
    CCSprite* image3 = CCSprite::create(PNG_P_RED, CCRectMake(0, 0, 24, 24));
    image3->setAnchorPoint(CCPointZero);
    image3->setPosition( ccp(_visibleSize.width / 3.5, _visibleSize.height * 0.6));
    this->addChild(image3);

    CCLabelBMFont* disc3 = CCLabelBMFont::create("Multiple Ball", FONT_WHITE);
    disc3->setScale(0.5);
    disc3->setAnchorPoint(CCPointZero);
    disc3->setPosition( ccp(image3->getPositionX() + image3->getContentSize().width + 15,
                            image3->getPositionY() - image3->getContentSize().height / 2));
    this->addChild(disc3);

    //紫
    CCSprite* image4 = CCSprite::create(PNG_P_VIOLET, CCRectMake(0, 0, 24, 24));
    image4->setAnchorPoint(CCPointZero);
    image4->setPosition( ccp(_visibleSize.width / 3.5, _visibleSize.height * 0.55));
    this->addChild(image4);

    CCLabelBMFont* disc4 = CCLabelBMFont::create("Bonus Score", FONT_WHITE);
    disc4->setScale(0.5);
    disc4->setAnchorPoint(CCPointZero);
    disc4->setPosition( ccp(image4->getPositionX() + image4->getContentSize().width + 15,
                            image4->getPositionY() - image4->getContentSize().height / 2));
    this->addChild(disc4);

    //黃
    CCSprite* image5 = CCSprite::create(PNG_P_YELLOW, CCRectMake(0, 0, 24, 24));
    image5->setAnchorPoint(CCPointZero);
    image5->setPosition( ccp(_visibleSize.width / 3.5, _visibleSize.height * 0.5));
    this->addChild(image5);

    CCLabelBMFont* disc5 = CCLabelBMFont::create("Add Ramain Ball", FONT_WHITE);
    disc5->setScale(0.5);
    disc5->setAnchorPoint(CCPointZero);
    disc5->setPosition( ccp(image5->getPositionX() + image5->getContentSize().width + 15,
                            image5->getPositionY() - image5->getContentSize().height / 2));
    this->addChild(disc5);

    //クレジット
    CCLabelBMFont* title2 = CCLabelBMFont::create("Credits", FONT_BLUE);
    title2->setScale(0.7);
    title2->setPosition( ccp(_visibleSize.width / 2, _visibleSize.height * 0.4));
    this->addChild(title2);

    CCLabelBMFont* disc6 = CCLabelBMFont::create("JEWEL SAVIOR FREE", FONT_WHITE);
    disc6->setScale(0.5);
    disc6->setPosition( ccp(_visibleSize.width / 2, _visibleSize.height * 0.3));
    this->addChild(disc6);

    CCLabelBMFont* disc7 = CCLabelBMFont::create("http://www.jewel-s.jp/", FONT_WHITE);
    disc7->setScale(0.4);
    disc7->setPosition( ccp(disc6->getPositionX(),
                            disc6->getPositionY() - disc6->getContentSize().height));
    this->addChild(disc7);

}

void HelpScene::makeBackButton()
{
    CCMenuItemImage *item = CCMenuItemImage::create(
                                                    PNG_BACK,
                                                    PNG_BACK,
                                                    this,
                                                    menu_selector(HelpScene::onTapBackButton));

    if (!item) return;
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    item->setPosition(GHelper::convI720toCC(20, visibleSize.height * 0.1));
    CCMenu* menu = CCMenu::create(item, NULL);
    menu->setPosition(CCPointZero);
    if (!menu) return;
    this->addChild(menu, kZOrderTop, kTagBack);
}


void HelpScene::onTapBackButton()
{
    CCDirector::sharedDirector()->popScene();
}

void HelpScene::keyBackClicked()
{
    CCDirector::sharedDirector()->popScene();
}

