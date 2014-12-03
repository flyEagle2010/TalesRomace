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
    std::vector<Button*> buttons;
    for(int i=1000;i<1006;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        btn->addClickEventListener(CC_CALLBACK_1(Team::onButtonClick, this));
        if(i<1003){
            buttons.push_back(btn);
        }
    }
    this->tabBar=TabBar::create(buttons);
    this->tabBar->setIndex(0);
    this->tabBar->retain();
    
    
    this->resetUI();
    return true;
}

void Team::resetUI()
{
    int gap=10;
    Card* card=Card::create();
    Size wsize=Director::getInstance()->getWinSize();
    Size size=this->cardList->getInnerContainerSize();
    Vec2 center=Vec2(size.width*0.5,size.height*0.5);
    this->cardList->setInnerContainerSize(Size(size.width,(1+ceil(25/4.f))*card->getSize().height));
    size=this->cardList->getInnerContainerSize();
    for(int i=0;i<25;i++){
        Card* card=Card::create();
        card->click=CC_CALLBACK_1(Team::selectCard, this);
        this->cardList->addChild(card);
        Size cardSize=card->getSize();
        card->setPosition(Vec2(cardSize.width*0.5+(cardSize.width+gap)*(i%4),size.height-cardSize.height*0.5-(cardSize.height+gap)*(i/4))-center);
        if(i==0){
            card->setSelect(true);
            this->card=card;
        }
    }
    size=this->aoyiList->getInnerContainerSize();
    for(int i=0;i<10;i++){
        AoyiItem* item=AoyiItem::create();
        this->aoyiList->addChild(item);
        Size itemSize=item->getSize();
        item->setPosition(Vec2(itemSize.width*0.5,(itemSize.height+gap)*i+itemSize.height*0.5)-center);
        this->aoyiList->setInnerContainerSize(Size(size.width,(itemSize.height+gap)*10));
    }
}

void Team::selectCard(Widget* card)
{
    log("select card");
    this->card->setSelect(false);
    this->card=(Card*)card;
    this->card->setSelect(true);
}

void Team::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000: //tab0
        {
            this->tabBar->setIndex(0);
            break;
        }
        case 1001: //tab1
        {
            this->tabBar->setIndex(1);
            break;
        }
        case 1002: //tab2
        {
            this->tabBar->setIndex(2);
            break;
        }
        case 1003: //保存
        {
            break;
        }
        case 1004: //排序
        {
            break;
        }
        case 1005: //返回
        {
            this->clear(true);
            break;
        }
    }
}

void Team::onExit()
{
    this->tabBar->release();
    BaseUI::onExit();
}