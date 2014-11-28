//
//  Map.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/11.
//
//

#ifndef __TalesRomance__Map__
#define __TalesRomance__Map__

#include <stdio.h>
#include "BaseUI.h"

using namespace cocos2d;

class Map : public BaseUI{
public:
    static Map* create();
    bool init();
private:
    void onButtonClick(Ref* pSender);
};
#endif /* defined(__TalesRomance__Map__) */
