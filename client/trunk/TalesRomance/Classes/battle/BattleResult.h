//
//  BattleResult.h
//  TalesRomance
//
//  Created by qll on 14/12/8.
//
//

#ifndef __TalesRomance__BattleResult__
#define __TalesRomance__BattleResult__

#include <stdio.h>
#include "BaseUI.h"
#include "HomeScene.h"

class BattleResult : public BaseUI {
    LoadingBar* haoganBar;
    Text* nameLabel;
    Text* coinLabel;
    Sprite* potrait;
    Sprite* star;
    Sprite* win;
private:
    virtual void onButtonClick(Ref *pSender);
    virtual void onExit();
public:
    static BattleResult* create();
    bool init();
    
};

#endif /* defined(__TalesRomance__BattleResult__) */
