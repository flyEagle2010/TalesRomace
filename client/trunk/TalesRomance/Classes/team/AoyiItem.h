//
//  AoyiItem.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#ifndef __TalesRomance__AoyiItem__
#define __TalesRomance__AoyiItem__

#include <stdio.h>
#include "BaseUI.h"
#include "XGroup.h"
#include "XSkill.h"

class AoyiItem : public BaseUI {
    Sprite* bg;
    ImageView* typeIcon;
    Text* nameLabel;
    Vector<ImageView*> cards;
    int xid;
public:
    static AoyiItem* create(int xid);
    bool init(int xid);
    void resetUI();
    Size getSize();
};

#endif /* defined(__TalesRomance__AoyiItem__) */
