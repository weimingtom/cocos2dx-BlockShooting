//
//  BarSprite.h
//  BrockShooting
//
//  Created by sakura on 2014/04/21.
//
//

#ifndef __BrockShooting__BarSprite__
#define __BrockShooting__BarSprite__

#include "cocos2d.h"
#include "Config.h"

#define PNG_BAR "bar.png"

#define TAG_BAR 1001

class BarSprite : public cocos2d::CCSprite
{
protected:

public:

    BarSprite();
    virtual ~BarSprite();

    static BarSprite* createWithBarSize(float width, float height);

    virtual bool initWithBarSize(float width, float height);
};


#endif /* defined(__BrockShooting__BarSprite__) */
