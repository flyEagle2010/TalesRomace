//
//  StandDraw.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/24.
//
//

#include "StandDraw.h"

StandDraw* StandDraw::create()
{
    StandDraw* pRet=new StandDraw();
    if(pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool StandDraw::init()
{
    Size size=Director::getInstance()->getWinSize();
    LayerColor::initWithColor(Color4B(0, 0, 0, 200),size.width,size.height/2.f);
    
    return true;
}

void StandDraw::play()
{
    Label* label=Label::createWithTTF("合体技能大招", "fonts/Marker Felt.ttf", 48);
    this->addChild(label,1);
    label->setPosition(Vec2(200,320));
    label->setTextColor(Color4B(255,255,100,255));
    label->runAction(MoveTo::create(0.5, Vec2(1136,320)));
    
    
    CallFunc* cf=CallFunc::create(std::bind(&LayerColor::removeFromParent, this));
    //Sequence* sq=Sequence::create(DelayTime::create(1.5),cf, NULL);
    
    //this->runAction(sq);
}