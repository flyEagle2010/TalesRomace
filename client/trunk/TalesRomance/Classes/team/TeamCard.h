//
//  TeamCard.h
//  TalesRomance
//
//  Created by qll on 15/1/6.
//
//

#ifndef __TalesRomance__TeamCard__
#define __TalesRomance__TeamCard__

#include <stdio.h>
#include "BaseUI.h"
#include "TabBar.h"
#include "HomeScene.h"
#include "XGroup.h"
#include "XCard.h"

class TeamCard : public BaseUI {
    TabBar* tabBar;
    Node* aoYiPanel;
    Node* cardPanel;
    ListView* cardList;
    ListView* aoYiList;
public:
    static TeamCard* create();
    bool init();
    void resetUI();
private:
    void onButtonClick(cocos2d::Ref *pSender);
};

#endif /* defined(__TalesRomance__TeamCard__) */
