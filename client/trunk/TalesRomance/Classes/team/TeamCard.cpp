//
//  TeamCard.cpp
//  TalesRomance
//
//  Created by qll on 15/1/6.
//
//

#include "TeamCard.h"
TeamCard* TeamCard::create()
{
    TeamCard* pRet=new TeamCard();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool TeamCard::init()
{
    if(!BaseUI::init("TeamCard.csb", "teamcard.plist")){
        return false;
    }
    std::vector<Button*> buttons;
    for(int i=1000;i<1008;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        btn->addClickEventListener(CC_CALLBACK_1(TeamCard::onButtonClick, this));
        if(i>1001) buttons.push_back(btn);
    }
    this->tabBar=TabBar::create(buttons);
    this->tabBar->retain();
    
    this->aoYiPanel=this->ui->getChildByName("aoYiPanel");
    this->cardPanel=this->ui->getChildByName("cardPanel");
    this->cardList=dynamic_cast<ListView*>(this->ui->getChildByName("cardList"));
    this->aoYiList=dynamic_cast<ListView*>(this->aoYiPanel->getChildByName("aoyiList"));
    
    this->cardPanel->setVisible(false);
    
    this->resetUI();
    return true;
}

void TeamCard::resetUI()
{
    int gap=10;
    Card* card=Card::create();
    Size wsize=Director::getInstance()->getWinSize();
    Size size=this->cardList->getInnerContainerSize();
    Vec2 center=Vec2(wsize.width*0.5,wsize.height*0.5);
    center=Vec2(0, 0);
    this->cardList->setItemModel(card);
    
    //size=this->cardList->getInnerContainerSize();
    for(int i=0;i<25;i++){
        Card* card=Card::create();
        //card->click=CC_CALLBACK_1(Team::selectCard, this);
        this->cardList->addChild(card);
        //Size cardSize=card->getSize();
        //card->setPosition(Vec2(cardSize.width*0.5+(cardSize.width+gap)*(i%4),size.height-cardSize.height*0.5-(cardSize.height+gap)*(i/4))-center);
        //this->cardList->pushBackDefaultItem();
    }
    //size=this->aoYiList->getInnerContainerSize();
//    this->aoYiList=ListView::create();
//    this->aoYiList->setContentSize(Size(290,400));
//    this->aoYiList->setDirection(ui::ScrollView::Direction::VERTICAL);
//    //this->aoYiList->setPosition(Vec2(320,200));
//    this->addChild(aoYiList);
    
    
//    AoyiItem* item=AoyiItem::create();
//    this->aoYiList->setItemModel(item);
//    this->aoYiList->addChild(item);
    this->aoYiList->setItemsMargin(42);
    for(int i=0;i<30;i++){
//        this->aoYiList->pushBackDefaultItem();
        
        AoyiItem* item=AoyiItem::create();
        //item->setPosition(Vec2(i*10,320));
        this->aoYiList->addChild(item);
    }
}

void TeamCard::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    log("tag:%d,index:%d",btn->getTag(),tabBar->getIndex());
    switch (btn->getTag()) {
        case 1000: //gohome
        {
            Manager::getInstance()->switchScence(HomeScene::createScene());
            break;
        }
        case 1001: //返回
        {
            this->clear(true);
            break;
        }
        case 1002: //tab0
        {
            this->tabBar->setIndex(0);
            break;
        }
        case 1003: //tab1
        {
            this->tabBar->setIndex(1);
            break;
        }
        case 1004: //tab2
        {
            this->tabBar->setIndex(2);
            break;
        }
        case 1005: //tab4
        {
            this->tabBar->setIndex(3);
            break;
        }
        case 1006: //tab5
        {
            this->tabBar->setIndex(4);
            break;
        }
        case 1007: //tab6
        {
            this->tabBar->setIndex(5);
            break;
        }

    }}