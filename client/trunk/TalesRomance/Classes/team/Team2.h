//
//  Team2.h
//  TalesRomance
//
//  Created by qll on 15/1/5.
//
//

#ifndef __TalesRomance__Team2__
#define __TalesRomance__Team2__

#include <stdio.h>
#include "BaseUI.h"
#include "HomeScene.h"
#include "DataManager.h"

class Team2 : public BaseUI {
    
    ListView* list;
    Vector<Node*> items;
public:
    json_t* teamData;
public:
    static Team2* create();
    bool init();
    void resetUI();
    void request();
private:
    void onButtonClick(Ref* pSender);
    void onTouchEnded(Touch *touch, Event *unusedEvent);
    void initNetEvent();
};
#endif /* defined(__TalesRomance__Team2__) */
