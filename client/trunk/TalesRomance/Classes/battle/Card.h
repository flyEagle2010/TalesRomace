//
//  Card.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#ifndef __TalesRomance__Card__
#define __TalesRomance__Card__

#include <stdio.h>
#include "BaseUI.h"
#include "Clip.h"
#include "BattleMgr.h"

class Card : public BaseUI
{
public:
    static Card* create(int index);
    bool init();
    
    void move(float delay);
    void useSkill();
    void mergeToHero();
    void playEnd();
private:
    int index;
};

#endif /* defined(__TalesRomance__Card__) */
