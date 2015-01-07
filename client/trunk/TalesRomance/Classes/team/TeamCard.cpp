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
    
    this->aoYiPanel=this->ui->getChildByName("aoYiPanel");
    this->cardPanel=this->ui->getChildByName("cardPanel");
    this->cardList=dynamic_cast<ui::ScrollView*>(this->ui->getChildByName("cardList"));
    this->aoYiList=dynamic_cast<ListView*>(this->aoYiPanel->getChildByName("aoyiList"));
    
    Size wsize=Director::getInstance()->getWinSize();
    Size csize=Size(290,441);
    BattleCard* card=BattleCard::create(0);
    this->cardPanel->addChild(card);
    Size size=(csize-wsize)*0.5;
    card->setPosition(Vec2(size.width,size.height+88));
    
    std::vector<Button*> buttons;
    for(int i=1000;i<1008;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        btn->addClickEventListener(CC_CALLBACK_1(TeamCard::onButtonClick, this));
        if(i>1001) buttons.push_back(btn);
    }
    this->tabBar=TabBar::create(buttons);
    this->tabBar->retain();
    
    for(int i=1008;i<1010;i++){
        Button* btn=(Button*)this->cardPanel->getChildByTag(i);
        btn->addClickEventListener(CC_CALLBACK_1(TeamCard::onButtonClick, this));
    }
    
    this->cardPanel->setVisible(false);
    
    this->resetUI();
    return true;
}

void TeamCard::resetUI()
{
    this->initCards(nullptr);
    
    std::vector<int> items=this->getAoYiData(2, 3);
    for(int i=0;i<items.size();i++){
        AoyiItem* aoyi=AoyiItem::create(items.at(i));
        this->aoYiList->addChild(aoyi);
    }
}

void TeamCard::initCards(json_t *jsonArr)
{
    int gap=10;
    Size size=this->cardList->getInnerContainerSize();
    for(int i=0;i<25;i++){
        Card* card=Card::create();
        card->click=CC_CALLBACK_1(TeamCard::selectCard, this);
        this->cardList->getInnerContainer()->addChild(card);
        Size cardSize=card->getSize();
        card->setPosition(Vec2(cardSize.width*0.5+gap+(cardSize.width+gap)*(i%3),(size.height-cardSize.height*0.5)-(cardSize.height+gap)*(i/3)));
    }
}

void TeamCard::filterCard(int type)
{
    return;
    
    if(type==0){
        this->initCards(cards);
        return;
    }
    json_t* jarr=json_array();
    int size=json_array_size(jarr);
    for(int i=0;i<size;i++){
        json_t* json=json_array_get(jarr, i);
        if(json_integer_value(json_object_get(json, "type")) == type){
            
        }
    }
    json_array_append(jarr, json_integer(3));
    
    this->initCards(jarr);
}

void TeamCard::selectCard(Widget* card)
{
    if(this->card==nullptr){
        this->card=dynamic_cast<Card*>(card);
    }
    this->card->setSelect(false);
    this->card=dynamic_cast<Card*>(card);
    this->card->setSelect(true);
    
    this->cardPanel->setVisible(true);
    this->aoYiPanel->setVisible(false);
}

std::vector<int> TeamCard::getAoYiData(int type1,int type2)
{
    XGroup* xgroup=XGroup::record(Value(0));
    std::vector<int> items;
    
    for (rapidjson::GenericValue<rapidjson::UTF8<> >::MemberIterator it=xgroup->doc.MemberonBegin(); it != xgroup->doc.MemberonEnd(); it++ )
    {
        rapidjson::Value& item=it->value; //567
        int group=item["group"].GetInt();
        std::vector<int> arr=Utils::getNum(group);
        for(int i=0;i<arr.size();i++){
            int num=arr.at(i);
            if(num==0) continue;
            if(num==type1 || num==type2){
                items.push_back(item["id"].GetInt());
            }
        }
    }
    return items;
}

void TeamCard::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    int tag=btn->getTag();
    log("tag:%d,index:%d",btn->getTag(),tabBar->getIndex());
    switch (tag) {
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
        case 1002: //tab0 黑白红绿蓝黄
        case 1003: //tab1
        case 1004: //tab2
        case 1005: //tab4
        case 1006: //tab5
        case 1007: //tab6
        {
            this->tabBar->setIndex(tag-1002);
            this->filterCard(tag-1002);
            break;
        }
        
        case 1008: //上场
        {
            this->aoYiPanel->setVisible(true);
            this->cardPanel->setVisible(false);
            break;
        }
        case 1009: //下场
        {
            this->aoYiPanel->setVisible(true);
            this->cardPanel->setVisible(false);
            break;
        }

    }}