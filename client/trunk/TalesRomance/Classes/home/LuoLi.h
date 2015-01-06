//
//  LuoLi.h
//  TalesRomance
//
//  Created by qll on 15/1/5.
//
//

#ifndef __TalesRomance__LuoLi__
#define __TalesRomance__LuoLi__

#include <stdio.h>
#include "cocos2d.h"
#include "Clip.h"
using namespace cocos2d;
class LuoLi : public Node
{
    Clip* face;
    Sprite* topHair;
    Sprite* backHair;
    Sprite* dress;
    
public:
    static LuoLi* create();
    bool init();
    void setDess(std::string fName);
    void setBackHair(std::string fName);
    void setTopHair(std::string fName);
    void setFace(std::string fName);
};
#endif /* defined(__TalesRomance__LuoLi__) */
