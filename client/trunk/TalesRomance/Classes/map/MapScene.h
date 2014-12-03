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
#include "XMap.h"

class MapScene : public BaseUI{
    Sprite* bg;
    Vector<Sprite*> gates;
    ScrollView* scrollView;
public:
    static MapScene* create();
    bool init();
    void resetUI();
private:
    void onButtonClick(Ref* pSender);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
};
#endif /* defined(__TalesRomance__MapScene__) */
