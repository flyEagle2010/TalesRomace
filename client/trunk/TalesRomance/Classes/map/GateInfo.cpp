//
//  GateInfo.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#include "GateInfo.h"

GateInfo* GateInfo::create(int gateID)
{
    GateInfo* pRet=new GateInfo();
    if(pRet && pRet->init(gateID)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool GateInfo::init(int gateID)
{
    if(!BaseUI::init("GateInfo.csb", "GateInfo.plist")){
        return false;
    }
    this->gateID=gateID;
    this->friendList=(ScrollView*)this->ui->getChildByName("friendList");
    this->cdLabel=(Text*)this->ui->getChildByName("cdLabel");
    this->staminaLabel=(Text*)this->ui->getChildByName("staminaLabel");
    this->numLabel=(Text*)this->ui->getChildByName("numLabel");
    this->desLabel=(Text*)this->ui->getChildByName("desLabel");
    this->portait=(Sprite*)this->ui->getChildByName("portait");
    
    for(int i=0;i<RWARD_NUM;i++)
    {
        Sprite* icon=(Sprite*)this->ui->getChildByName("icon"+Value(i).asString());
        this->icons.pushBack(icon);
        icon=(Sprite*)this->ui->getChildByName("iconRim"+Value(i).asString());
        this->rims.pushBack(icon);
    }
    
    for(int i=1;i<Group_NUM+1;i++){
        Sprite* groupRim=(Sprite*)this->ui->getChildByName("groupRim"+Value(i).asString());
        groupRim->setVisible(false);
        this->groups.pushBack(groupRim);
    }
    
    Button* btn=(Button*)this->ui->getChildByName("btn_begin");
    btn->addClickEventListener(CC_CALLBACK_1(GateInfo::onButtonClick, this));
    btn=(Button*)this->ui->getChildByName("btn_clear");
    btn->addClickEventListener(CC_CALLBACK_1(GateInfo::onButtonClick, this));
    btn=(Button*)this->ui->getChildByName("btn_back");
    btn->addClickEventListener(CC_CALLBACK_1(GateInfo::onButtonClick, this));
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {return true;};
    listener->onTouchEnded = CC_CALLBACK_2(GateInfo::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->resetUI();
    
    return true;
}

void GateInfo::resetUI()
{
    int gap=10;
    Size wsize=Director::getInstance()->getWinSize();
    Size size=this->friendList->getInnerContainerSize();
    Vec2 center=Vec2(wsize.width*0.5,wsize.height*0.5);
    for(int i=0;i<10;i++){
        Card* card=Card::create();
        card->click=CC_CALLBACK_1(GateInfo::selectFriend, this);
        this->friendList->addChild(card);
        Size cardSize=card->rim->getContentSize();
        card->setPosition(Vec2(cardSize.width*0.5+i*(cardSize.width+gap),size.height*0.6));
        this->friendList->setInnerContainerSize(Size((gap+cardSize.width)*10,size.height));
        if(i==0){
            card->setSelect(true);
        }
    }
    XMap* xmap=XMap::record(Value(this->gateID));
    //this->numLabel->setString(xmap->getName());
    //this->desLabel->setString(xmap->getDesc());
}

void GateInfo::selectFriend(cocos2d::ui::Widget *card)
{
    log("------");
}

void GateInfo::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
    for(int i=0;i<this->groups.size();i++){
        Node* item=this->groups.at(i);
        Vec2 position=item->getPosition();
        Size size=item->getContentSize();
        Rect rect=Rect(position.x-size.width*0.5,position.y-size.height*0.5,size.width,size.height);
        item->setVisible(rect.containsPoint(touch->getLocation()));
    }
}

void GateInfo::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000: //扫荡
        {
            break;
        }
        case 1001: //开始
        {
            Maze* maze=Maze::create();
            maze->show(this);
            break;
        }
        case 1002: //返回
        {
            this->clear(true);
            break;
        }
    }
}