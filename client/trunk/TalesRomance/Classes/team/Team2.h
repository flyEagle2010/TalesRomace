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

class Team2 : public BaseUI {
    
    ListView* list;
    Vector<Node*> items;
public:
    static Team2* create();
    bool init();
    void resetUI();
private:
    void onButtonClick(Ref* pSender);
    void onTouchEnded(Touch *touch, Event *unusedEvent);

};
#endif /* defined(__TalesRomance__Team2__) */
