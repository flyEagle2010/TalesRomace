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
#include "AoyiItem.h"

class TeamCard : public BaseUI {
    TabBar* tabBar;
    Node* aoYiPanel;
    Node* cardPanel;
    ui::ScrollView* cardList;
    ListView* aoYiList;
    Card* card;
    json_t* data;
    json_t* cards;
    int index;
public:
    static TeamCard* create(json_t* data,int index);
    bool init(json_t* data,int index);
    void resetUI();
private:
    void initNetEvent();
    void onButtonClick(cocos2d::Ref *pSender);
    void onIconClick(Ref* pSender);
    void selectCard(Widget* card);
    std::vector<int> getAoYiData(int num);
    void filterCard(int type);
    void initCard();
    void initBag(json_t* jsonArr);
    void initAoYi();
};

#endif /* defined(__TalesRomance__TeamCard__) */
