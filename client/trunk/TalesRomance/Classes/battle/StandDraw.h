//
//  StandDraw.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/24.
//
//

#ifndef __TalesRomance__StandDraw__
#define __TalesRomance__StandDraw__

#include <stdio.h>
#include "cocos2d.h"
#include "BaseUI.h"
#include "Clip.h"

class StandDraw : public LayerColor
{
public:
    static StandDraw* create();
    bool init();
    float play();
private:
    Clip* bgClip;
    Clip* topClip;
    Sprite* icon;
};

#endif /* defined(__TalesRomance__StandDraw__) */
