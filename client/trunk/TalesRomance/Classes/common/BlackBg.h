//
//  BlackBg.h
//  fancyHeart
//
//  Created by zhai on 14-6-25.
//
//

#ifndef __fancyHeart__BlackBg__
#define __fancyHeart__BlackBg__

#include <iostream>
#include "cocos2d.h"
#include "ui/UILayout.h"
USING_NS_CC;
class BlackBg:public cocos2d::ui::Layout
{
public:
    static BlackBg* getInstance();
    virtual bool init(cocos2d::Size size);
    virtual void onExit();
    void show();
    void hide();
};
#endif /* defined(__fancyHeart__BlackBg__) */
