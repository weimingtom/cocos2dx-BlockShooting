//
//  Animations.cpp
//  BrockShooting
//
//  Created by sakura on 2014/05/07.
//
//

#include "Animations.h"
#include "Config.h"

USING_NS_CC;

CCFiniteTimeAction* Animations::topMiniAnimation()
{
    //top画面女の子のフレームアニメーション
    CCAnimation * anim = CCAnimation::create();

    CCSpriteFrame* sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI1_1);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI1_2);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI1_3);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI1_4);
    anim->addSpriteFrame(sprite);
    anim->setLoops(-1);
    anim->setDelayPerUnit(0.4f);
    CCFiniteTimeAction* repeat = CCAnimate::create(anim);
    return repeat;
}

CCFiniteTimeAction* Animations::topLabelAction()
{
    //Playボタンのアニメーション
    CCDelayTime* delay1 = CCDelayTime::create(2);
    CCScaleTo* scaleUp = CCScaleTo::create(0.3, 1.1);
    CCScaleTo* scaleDown = CCScaleTo::create(0.3, 1);
    CCSequence* seq = CCSequence::create(delay1, scaleUp, scaleDown, NULL);
    CCRepeatForever* repeat = CCRepeatForever::create(seq);

    return repeat;
}

CCFiniteTimeAction* Animations::gameClearAction(CCObject* target, SEL_CallFunc selector)
{
    //Gameクリア時に表示するラベルのアニメーション
    CCDelayTime* delay1 = CCDelayTime::create(0.5);
    CCScaleTo* scaleUp1 = CCScaleTo::create(0.4, 4.5);
    CCDelayTime* delay2 = CCDelayTime::create(0.2);
    CCScaleTo* scaleDown1 = CCScaleTo::create(0.2, 2);
    CCScaleTo* scaleUp2 = CCScaleTo::create(0.1, 2.4);
    CCScaleTo* scaleDown2 = CCScaleTo::create(0.1, 2);

    CCDelayTime* delay3 = CCDelayTime::create(3.5);
    CCScaleTo* scaleDown3 = CCScaleTo::create(0.1, 0);

    CCCallFunc* func = CCCallFunc::create(target, selector);

    return CCSequence::create(delay1, scaleUp1, delay2, scaleDown1, scaleUp2, scaleDown2, delay3, scaleDown3, func, NULL);
}

CCFiniteTimeAction* Animations::gameAddingScoreAction()
{
    //Gameクリア時に残りボールがあった時に表示するラベルのアニメーション
    CCDelayTime* delay1 = CCDelayTime::create(0.5);
    CCScaleTo* scaleUp1 = CCScaleTo::create(0.2, 1.0);
    CCDelayTime* delay2 = CCDelayTime::create(0.2);
    CCScaleTo* scaleDown1 = CCScaleTo::create(0.2, 0.8);
    CCDelayTime* delay3 = CCDelayTime::create(2.5);
    CCScaleTo* scaleDown2 = CCScaleTo::create(0.7, 0);

    return CCSequence::create(delay1, scaleUp1, delay2, scaleDown1, delay3, scaleDown2, NULL);
}

CCFiniteTimeAction* Animations::retryButtonAction()
{
    CCDelayTime* delay1 = CCDelayTime::create(1);
    CCScaleTo* scaleUp = CCScaleTo::create(0.1, 1.5);
    CCDelayTime* delay2 = CCDelayTime::create(0.5);
    CCScaleTo* scaleDown = CCScaleTo::create(0.3, 1);
    CCSequence* seq = CCSequence::create(delay1, scaleUp, delay2, scaleDown, NULL);
    CCRepeatForever* repeat = CCRepeatForever::create(seq);

    return repeat;
}

CCFiniteTimeAction* Animations::getItemFallAction(CCSprite* block)
{
    CCFiniteTimeAction* actionMove = CCMoveTo::create( 3.0, ccp(block->getPositionX(), 0) );
    CCSequence* seq = CCSequence::create(actionMove, NULL);
    return seq;
}

CCFiniteTimeAction* Animations::getItemLabelAction(CCNode* bar, CCObject* target, SEL_CallFunc selector)
{
    CCScaleTo* scaleUp = CCScaleTo::create(0.1, 0.3);
    CCFiniteTimeAction* move = CCMoveTo::create(0.2, ccp(bar->getPositionX(), bar->getPositionY() + bar->getContentSize().height / 2  + 25) );
    CCDelayTime* delay1 = CCDelayTime::create(0.1);
    CCScaleTo* scaleDown = CCScaleTo::create(0.1, 0);
    CCCallFunc* func = CCCallFunc::create(target, selector);
    CCSequence* seq = CCSequence::create(scaleUp, move, delay1, scaleDown, func, NULL);
    return seq;
}

CCFiniteTimeAction* Animations::winMiniAnimation()
{
    CCAnimation * anim = CCAnimation::create();

    CCSpriteFrame* sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI2_1);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI2_2);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI2_3);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI2_4);
    anim->addSpriteFrame(sprite);
    anim->setLoops(-1);
    anim->setDelayPerUnit(0.4f);
    CCFiniteTimeAction* repeat = CCAnimate::create(anim);
    return repeat;
}

CCFiniteTimeAction* Animations::gameoverMiniAnimation()
{
    CCAnimation * anim = CCAnimation::create();

    CCSpriteFrame* sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI3_1);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI3_2);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI3_3);
    anim->addSpriteFrame(sprite);
    sprite =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(PNG_MINI3_4);
    anim->addSpriteFrame(sprite);
    anim->setLoops(-1);
    anim->setDelayPerUnit(0.4f);
    CCFiniteTimeAction* repeat = CCAnimate::create(anim);
    return repeat;
}
