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

class AoyiItem : public BaseUI {
    Sprite* bg;
    Sprite* typeIcon;
    Sprite* cardIcon0;
    Text* nameLabel;
    
public:
    static AoyiItem* create();
    bool init();
    void resetUI();
    Size getSize();
};

#endif /* defined(__TalesRomance__AoyiItem__) */
