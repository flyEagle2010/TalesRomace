//
//  Team.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#include "Team.h"
Team* Team::create()
{
    Team* pRet=new Team();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Team::init()
{
    if(!BaseUI::init("Team.csb", "Team.plist")){
        return false;
    }
    this->cardList=(ScrollView*)this->ui->getChildByName("cardList");
    this->aoyiList=(ScrollView*)this->ui->getChildByName("aoyiList");
    
    this->resetUI();
    return true;
}

void Team::resetUI()
{
    int gap=10;
    Card* card=Card::create();

    Size size=this->cardList->getInnerContainerSize();
    this->cardList->setInnerContainerSize(Size(size.width,ceil(25/4.f)*card->getSize().height));
    
    for(int i=0;i<25;i++){
        Card* card=Card::create();
        card->click=CC_CALLBACK_1(Team::selectCard, this);
        this->cardList->addChild(card);
        
        //card->setPosition(Vec2(cardSize.width*0.5+i*(cardSize.width+gap),size.height*0.5));
        //this->cardList->setInnerContainerSize(Size(cardSize.width,(cardSize.height+gap)*10));
        
        if(i==0){
            card->setSelect(true);
        }
    }
    size=this->aoyiList->getInnerContainerSize();
    for(int i=0;i<10;i++){
        AoyiItem* item=AoyiItem::create();
        this->aoyiList->addChild(item);
        Size itemSize=item->getSize();
        item->setPosition(Vec2(itemSize.width*0.5,(itemSize.height+gap)*i+itemSize.height*0.5));
        this->aoyiList->setInnerContainerSize(Size(size.width,(itemSize.height+gap)*10));
    }
}

void Team::selectCard(Widget* card)
{
    
}

void Team::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000: //保存
            
            break;
        case 1001: //排序
            
            break;
            
        case 1002: //返回
            
            break;
    }
}