//
//  Team.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#ifndef __TalesRomance__Team__
#define __TalesRomance__Team__

#include <stdio.h>
#include "BaseUI.h"
#include "Card.h"
#include "AoyiItem.h"


class Team : public BaseUI {
    ui::ScrollView* aoyiList;
    ui::ScrollView* cardList;
    
public:
    static Team* create();
    bool init();
    void resetUI();
private:
    void onButtonClick(Ref* pSender);
    void selectCard(Widget* card);

};

#endif /* defined(__TalesRomance__Team__) */
