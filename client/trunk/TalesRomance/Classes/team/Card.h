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
#include "XCard.h"
#include "XSkill.h"

class Card : public BaseUI {
    Sprite* icon;
    ImageView* atkIcon;
    ImageView* skillIcon;
    Text* level;
    Text* useTxt;
    Clip* selectRim;
    Vector<Sprite*> stars;
    typedef std::function<void(Widget*)> clickCallBack;
public:
    clickCallBack click;
    ImageView* rim;
    bool isUse;
    json_t* data;

public:
    static Card* create(json_t* data);
    bool init(json_t* data);
    void resetUI();

    void setSelect(bool isSelect);
    Size getSize();
    void setUse(bool isUse);
private:
    virtual void onTouchEnded(Touch *touch, Event *unusedEvent);
};


#endif /* defined(__TalesRomance__Card__) */
