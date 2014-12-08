//
//  GateInfo.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#ifndef __TalesRomance__GateInfo__
#define __TalesRomance__GateInfo__

#include <stdio.h>
#include "BaseUI.h"
#include "Card.h"
#include "Maze.h"
#include "XMap.h"

class GateInfo : public BaseUI
{
public:
    static GateInfo* create(int gateID);
    bool init(int gateID);
    void resetUI();
    virtual void onButtonClick(Ref *pSender);
private:
    void selectFriend(Widget* card);
    virtual void onTouchEnded(Touch *touch, Event *unusedEvent);

private:
    ui::ScrollView* friendList;
    Text* cdLabel;
    Text* staminaLabel;
    Text* numLabel;
    Text* desLabel;
    Sprite* portait;

    Vector<Sprite*> icons;
    Vector<Sprite*> rims;
    Vector<Node*> groups;
    
    int gateID;

};

#endif /* defined(__TalesRomance__GateInfo__) */
