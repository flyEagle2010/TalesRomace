//
//  LuoLi.cpp
//  TalesRomance
//
//  Created by qll on 15/1/5.
//
//

#include "LuoLi.h"

LuoLi* LuoLi::create()
{
    LuoLi* pRet=new LuoLi();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool LuoLi::init()
{
    this->backHair=Sprite::create("backHair_1.png");
    this->addChild(backHair);
    this->backHair->setPosition(Vec2(-20,273));
    
    Sprite* body=Sprite::create("body.png");
    this->addChild(body);
    body->setPosition(Vec2(-17,243));
    
    this->dress=Sprite::create("dress_1.png");
    this->addChild(dress);
    this->dress->setPosition(Vec2(-12,233));
    
//    this->face=Clip::create("biaoqing.plist", "biaoqing1");
//    this->addChild(face);
//    this->face->setPosition(Vec2(-12,376));
    Sprite* eye=Sprite::create("biaoqing_1.png");
    this->addChild(eye);
    eye->setPosition(Vec2(-12,376));
    
    this->topHair=Sprite::create("topHair_1.png");
    this->addChild(topHair);
    this->topHair->setPosition(Vec2(0,280));
    
    return true;
}

void LuoLi::setDess(std::string fName)
{
    
}

void LuoLi::setBackHair(std::string fName)
{
    
}

void LuoLi::setTopHair(std::string fName)
{
    
}

void LuoLi::setFace(std::string fName)
{
    
}