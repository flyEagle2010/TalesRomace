//
//  Card.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#ifndef __TalesRomance__Card__
#define __TalesRomance__Card__

#include <stdio.h>
#include "BaseUI.h"

class Card : public BaseUI {
    Sprite* icon;
    Sprite* atkIcon;
    Sprite* skillIcon;
    Text* level;
    Clip* selectRim;
    Vector<Sprite*> stars;
    typedef std::function<void(Widget*)> clickCallBack;
    json_t* data;
public:
    Sprite* rim;
    clickCallBack click;

public:
    static Card* create();
    bool init();
    void setData();
    void setSelect(bool isSelect);
    Size getSize();
private:
    virtual void onTouchEnded(Touch *touch, Event *unusedEvent);
};


#endif /* defined(__TalesRomance__Card__) */
