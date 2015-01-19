//
//  TeamCard.cpp
//  TalesRomance
//
//  Created by qll on 15/1/6.
//
//

#include "TeamCard.h"
TeamCard* TeamCard::create(json_t* data,int index)
{
    TeamCard* pRet=new TeamCard();
    if(pRet && pRet->init(data,index)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool TeamCard::init(json_t* data,int index)
{
    if(!BaseUI::init("TeamCard.csb", "teamcard.plist")){
        return false;
    }
    this->data=data;
    this->index=index;
    this->cards=json_object_get(data, "cards");
    if(this->cards ==NULL){
        this->cards=json_array();
        json_array_append(cards, json_object());
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
    this->initCard();
    this->initAoYi();
    this->initBag(nullptr);
}

void TeamCard::initCard()
{
    int cardSize=json_array_size(cards);
    for(int i=1;i<4;i++){
        ImageView* rim=dynamic_cast<ImageView*>(this->aoYiPanel->getChildByName("rim"+Value(i-1).asString()));
        Sprite* card=dynamic_cast<Sprite*>(this->aoYiPanel->getChildByName("card"+Value(i-1).asString()));
        if(i >= cardSize){
            rim->setVisible(false);
            card->setVisible(false);
        }else{
            rim->setVisible(true);
            card->setVisible(true);
            
            json_t* json=json_array_get(cards, i);
            int xid=json_integer_value(json_object_get(json, "xid"));
            XCard* xcard=XCard::record(Value(xid));
            card->setDisplayFrame(Sprite::createWithSpriteFrameName("tuoErTouXiang_1.png")->displayFrame());
            rim->loadTexture("cardTypeRim_"+Value(xcard->getCardType()).asString()+".png",TextureResType::PLIST);
            rim->addClickEventListener(CC_CALLBACK_1(TeamCard::onIconClick, this));
        }
    }
}

void TeamCard::initAoYi()
{
    int num=0;
    for(int i=1;i<json_array_size(this->cards);i++){
        json_t* card=json_array_get(cards, i);
        json_t* jxid=json_object_get(card, "xid");
        if(jxid!=NULL){
            int xid=json_integer_value(jxid);
            int type=XCard::record(Value(xid))->getCardType();
            
            log("xid:%d,%d",xid,type);
            num += pow(10, i-1)*type;
        }
    }
    
    std::vector<int> items=this->getAoYiData(num);
    this->aoYiList->removeAllItems();
    for(int i=0;i<items.size();i++){
        AoyiItem* aoyi=AoyiItem::create(items.at(i));
        this->aoYiList->pushBackCustomItem(aoyi);
    }
    if(items.size()==1 || ((items.size()==2 && json_array_size(cards)==3))){
        json_t* aoyi=json_object();
        int aoyiID=items.at(0);
        //XGroup* xgroup=XGroup::record(Value(aoyiID));
        //XSkill* xskill=XSkill::record(Value(xgroup->getSkillId()));
        json_object_set(aoyi, "xid", json_integer(aoyiID));
        json_object_set(aoyi, "atk", json_integer(30));
        json_array_set(cards, 0, aoyi);
    }
}

void TeamCard::initBag(json_t *jsonArr)
{
    this->card=nullptr;
    
    int gap=10;
    Size size=this->cardList->getInnerContainerSize();
    XCard* xcard=XCard::record(Value(0));
    int i=0;
    this->cardList->removeAllChildren();
    
    for (rapidjson::GenericValue<rapidjson::UTF8<> >::MemberIterator it=xcard->doc.MemberonBegin(); it != xcard->doc.MemberonEnd(); it++ ){
        rapidjson::Value& item=it->value;
        int xid=item["id"].GetInt();
        json_t* cardData=json_object();
        json_object_set(cardData, "isUse", json_boolean(false));
        json_object_set(cardData, "xid", json_integer(xid));
        
        json_t* teams = DataManager::getInstance()->getTeamData();

        for(int j=0;j<json_array_size(teams);j++){
            json_t* cards=json_object_get(json_array_get(teams, j),"cards");
            
            for(int i=0;i<json_array_size(cards);i++){
                int cid=json_integer_value(json_object_get(json_array_get(cards, i), "xid"));
                if(cid==xid){
                    json_object_set(cardData, "isUse", json_boolean(true));
                    break;
                }
            }
        }
        Card* card=Card::create(cardData);

        card->click=CC_CALLBACK_1(TeamCard::selectCard, this);
        this->cardList->getInnerContainer()->addChild(card);
        Size cardSize=card->getSize();
        card->setPosition(Vec2(cardSize.width*0.5+gap+(cardSize.width+gap)*(i%3),(size.height-cardSize.height*0.5)-(cardSize.height+gap)*(i/3)));
        i++;
    }
//    for(int i=0;i<25;i++){
//        Card* card=Card::create();
//        card->click=CC_CALLBACK_1(TeamCard::selectCard, this);
//        this->cardList->getInnerContainer()->addChild(card);
//        Size cardSize=card->getSize();
//        card->setPosition(Vec2(cardSize.width*0.5+gap+(cardSize.width+gap)*(i%3),(size.height-cardSize.height*0.5)-(cardSize.height+gap)*(i/3)));
//    }
}

void TeamCard::filterCard(int type)
{
    return;
    
    if(type==0){
        this->initBag(nullptr);
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
    
    this->initBag(jarr);
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
    
    this->cardPanel->getChildByName("btn_leave")->setVisible(this->card->isUse);
    this->cardPanel->getChildByName("btn_join")->setVisible(!this->card->isUse);
    
}

std::vector<int> TeamCard::getAoYiData(int num)
{
    XGroup* xgroup=XGroup::record(Value(0));
    std::vector<int> items;
    
    for (rapidjson::GenericValue<rapidjson::UTF8<> >::MemberIterator it=xgroup->doc.MemberonBegin(); it != xgroup->doc.MemberonEnd(); it++ ){
        rapidjson::Value& item=it->value; //567
        int group=item["group"].GetInt();
        if(num==0){
            items.push_back(item["id"].GetInt());
            continue;
        }
        
        std::vector<int> groups=Utils::getNum(group);
        std::vector<int> types=Utils::getNum(num);
        int index=0;
        for(int i=0;i<types.size();i++){
            if(find(groups.begin(), groups.end(), types[i]) != groups.end()){
                index++;
            }
        }
        if(index==types.size()){
            items.push_back(item["id"].GetInt());
        }
    }
    return items;
}

void TeamCard::onIconClick(cocos2d::Ref *pSender)
{
    ImageView* rim=(ImageView*) pSender;
    int tag=rim->getTag();
    //下阵
    rim->setVisible(false);
    this->aoYiPanel->getChildByName("card"+Value(tag-1).asString())->setVisible(false);
    json_array_remove(this->cards, tag);
    this->initBag(nullptr);
    
    this->initAoYi();

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
            Team2* team=dynamic_cast<Team2*>(this->preUI);
            json_object_set(data, "cards", this->cards);
            json_array_set(team->teamsJson, this->index, this->data);
            team->resetUI();

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
            json_object_set(this->card->data, "isUsed", json_boolean(true));
            json_array_append(this->cards, this->card->data);
            
            this->card->setUse(true);
            this->initAoYi();

            this->initCard();
            break;
        }
        case 1009: //下场
        {
            this->aoYiPanel->setVisible(true);
            this->cardPanel->setVisible(false);
            for (int i=0; i<json_array_size(cards); i++) {
                json_t* json=json_array_get(cards, i);
                int xid=json_integer_value(json_object_get(json, "xid"));
                int cid=json_integer_value(json_object_get(this->card->data, "xid"));
                if(xid==cid){
                    json_array_remove(cards, i);
                    break;
                }
            }
            json_array_set(cards, 0, json_object());

            this->card->setUse(false);
            this->initCard();
            this->initAoYi();
            break;
        }

    }
}

void TeamCard::initNetEvent(){
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        json_t* msg=(json_t*)event->getUserData();
        int msgID=json_integer_value(json_object_get(msg, "msgID"));
        switch (msgID)
        {
            case C_TEAM_CARD:
            {
                break;
            }
            case C_TEAM_CHANGE_CARD:
            {
                break;
            }
            default:
                break;
        }
        
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
}