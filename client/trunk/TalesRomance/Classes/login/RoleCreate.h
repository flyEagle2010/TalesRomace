//
//  RoleCreate.h
//  TalesRomance
//
//  Created by qll on 14/12/18.
//
//

#ifndef __TalesRomance__RoleCreate__
#define __TalesRomance__RoleCreate__

#include <stdio.h>
#include "cocos2d.h"
#include "BaseUI.h"
#include "HomeScene.h"
#include "DataManager.h"

class RoleCreate : public BaseUI {
    
    void onButtonClick(Ref* pSender);
    void onTouchEnded(Touch *touch, Event *unusedEvent);
    void initNetEvent();
public:
    static RoleCreate* create();
    bool init();
    void resetUI();
    
};

#endif /* defined(__TalesRomance__RoleCreate__) */
