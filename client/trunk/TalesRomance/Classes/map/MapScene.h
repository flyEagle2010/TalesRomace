//
//  MapScene.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/11.
//
//

#ifndef __TalesRomance__MapScene__
#define __TalesRomance__MapScene__

#include <stdio.h>
#include "BaseUI.h"
#include "ImageBtton.h"
#include "GateInfo.h"
#include "XMap.h"
#include "HomeScene.h"
#include "BattleResult.h"

class MapScene : public BaseUI{
    Sprite* bg;
    Vector<Sprite*> gates;
    json_t* jnodes;
public:
    static Scene* createScene();
    static MapScene* create();
    bool init();
    void resetUI();
    
    ui::ScrollView* scrollView;

private:
    void onButtonClick(Ref* pSender);
    void onTouchEnded(Widget* pSender);
    void initNetEvent();
};
#endif /* defined(__TalesRomance__MapScene__) */
