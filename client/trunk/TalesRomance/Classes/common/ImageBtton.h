//
//  ImageBtton.h
//  TalesRomance
//
//  Created by qll on 14/12/4.
//
//

#ifndef __TalesRomance__ImageBtton__
#define __TalesRomance__ImageBtton__

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace ui;

class ImageButton : public Widget
{
    Sprite* sprite;
    typedef std::function<void(Widget*)> clickCallBack;

public:
    static ImageButton* create(Sprite* sprite);
    bool init(Sprite* sprite);
    clickCallBack touchEnd;
private:
    bool onTouchBegin(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);

};

#endif /* defined(__TalesRomance__ImageBtton__) */
