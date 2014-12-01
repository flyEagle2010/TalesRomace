//
//  Card.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#include "Card.h"

Card* Card::create()
{
    Card* pRet=new Card();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Card::init()
{
    if(!BaseUI::init("Card.csb", "common.plist")){
        return false;
    }
    this->icon=(Sprite*)this->ui->getChildByName("icon");
    this->rim=(Sprite*)this->ui->getChildByName("rim");
    this->atkIcon=(Sprite*)this->ui->getChildByName("atkIcon");
    this->skillIcon=(Sprite*)this->ui->getChildByName("skillIcon");
    this->level=(Text*)this->ui->getChildByName("level");
    
    this->selectRim=Clip::create("selected.plist", "kaPaiXuanZe",12);
    this->addChild(selectRim);
    this->selectRim->setVisible(false);
    
    for(int i=0;i<STAR_NUM;++i)
    {
        std::string name="icon"+Value(i).asString();
        Sprite* icon=(Sprite*)this->ui->getChildByName(name);
        this->stars.pushBack(icon);
    }
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {
        Size size=this->rim->getContentSize()*0.5;
        Vec2 vec=this->rim->getPosition();
        vec=this->convertToWorldSpace(vec);
        Rect rect=Rect(vec.x-size.width*0.5,vec.y-size.height*0.5,size.width,size.height);
        return rect.containsPoint(touch->getLocation());
    };
    listener->onTouchEnded = CC_CALLBACK_2(Card::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void Card::setData()
{
    
}

void Card::setSelect(bool isSelect)
{
    if(isSelect){
        this->selectRim->setVisible(true);
        this->selectRim->play(true);
    }else{
        this->selectRim->stopAllActions();
        this->selectRim->setVisible(false);
    }
}

Size Card::getSize()
{
    return this->rim->getContentSize();
}

void Card::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    if(touch->getStartLocation() == touch->getLocation()){
        this->click(this);
    }
}