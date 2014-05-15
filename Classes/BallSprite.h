//
//  BallSprite.h
//  BrockShooting
//
//  Created by sakura on 2014/04/17.
//
//

#ifndef __BrockShooting__BallSprite__
#define __BrockShooting__BallSprite__


#include "cocos2d.h"
#include "Config.h"

class BallSprite : public cocos2d::CCSprite
{
protected:

    //x方向の速度をあらわす変数＆アクセサ
    CC_SYNTHESIZE(int, m_vx, VelocityX);
    //y方向の速度をあらわす変数＆アクセサ
    CC_SYNTHESIZE(int, m_vy, VelocityY);

    void initVelocity();

    bool bounceBall(cocos2d::CCSize visibleSize);

    bool bounceBall(cocos2d::CCRect rect, kTag);
    
public:

    BallSprite();
    virtual ~BallSprite();

    static BallSprite* createWithBallScale(float size);

    virtual bool initWithBallScale(float scale);
};

#endif /* defined(__BrockShooting__BallSprite__) */
