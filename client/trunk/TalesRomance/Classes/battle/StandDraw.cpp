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
    LayerColor::initWithColor(Color4B(0, 0, 0, 200),size.width,size.height);
//    this->bg=Sprite::create("aoYiMaskBg.png");
//    this->bg->setPosition(Vec2(size.width*0.5,size.height*0.5));
//    this->addChild(bg);
    this->bgClip=Clip::create("aoYiBgGreen.plist", "aoYiBgGreen",12);
    this->addChild(bgClip);
    bgClip->setScale(5);
    bgClip->setPosition(Vec2(size.width*0.5,size.height*0.5));
    
    this->icon=Sprite::create("portrait.png");
    this->icon->setPosition(Vec2(0,size.height*0.5));
    this->addChild(icon);
    this->icon->setScale(1.5);
    
    this->topClip=Clip::create("aoyi.plist", "aoYiMask",12);
    this->topClip->setPosition(Vec2(size.width*0.5, size.height*0.5));
    this->addChild(topClip);
    this->topClip->setScale(4);
    
    std::string txt="合体技能大招";
    Label* label=Label::createWithTTF(txt, "Marker Felt.ttf", 48);
    this->addChild(label,5);
    label->setPosition(Vec2(568,320));
    //label->setTextColor(Color4B(255,100,255,255));
    return true;
}

float StandDraw::play()
{
    Label* label=Label::createWithTTF("合体技能大招", "Marker Felt.ttf", 48);
    this->addChild(label,5);
    label->setPosition(Vec2(200,320));
    label->setTextColor(Color4B(255,255,100,255));
    label->runAction(MoveTo::create(0.5, Vec2(1136,320)));
    
    this->bgClip->play(true);

    this->topClip->play();
    
    Size size=Director::getInstance()->getWinSize();
    this->icon->runAction(MoveBy::create(1, Vec2(size.width*0.5,0)));

    
    CallFunc* cf=CallFunc::create(std::bind(&LayerColor::removeFromParent, this));
    Sequence* sq=Sequence::create(DelayTime::create(1.8),cf, NULL);
    
    this->runAction(sq);
    
    return 1.8;
}