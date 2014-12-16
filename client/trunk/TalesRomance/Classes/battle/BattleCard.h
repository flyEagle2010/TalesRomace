//
//  BattleCard.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#ifndef __TalesRomance__BattleCard__
#define __TalesRomance__BattleCard__

#include <stdio.h>
#include "BaseUI.h"
#include "Clip.h"
#include "BattleMgr.h"

class BattleCard : public BaseUI
{
public:
    static BattleCard* create(int index);
    bool init();
    void reset(int index,int groupNum,Value data);
    void move();
    void startToCenter();
    void useSkill();
    void playRim();
    void playDispear();
    void mergeToHero();
    void playEnd();
private:
    int index;
    int groupNum;
    Value data;
};

#endif /* defined(__TalesRomance__BattleCard__) */
