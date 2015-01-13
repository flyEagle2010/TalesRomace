//
//  Team2.cpp
//  TalesRomance
//
//  Created by qll on 15/1/5.
//
//

#include "Team2.h"
Team2* Team2::create()
{
    Team2* pRet=new Team2();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Team2::init()
{
    //SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/teamcard.plist");

    if(!BaseUI::init("Team2.csb", "team2.plist")){
        return false;
    }
    for(int i=1000;i<1002;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        btn->addClickEventListener(CC_CALLBACK_1(Team2::onButtonClick, this));
    }
    for(int i=100;i<112;i++){
        Node* item=this->ui->getChildByTag(i);
        this->items.pushBack(item);
       
    }
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {return true;};
    listener->onTouchEnded = CC_CALLBACK_2(Team2::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this->ui->getChildByName("btn_goHome"));
    
    this->teamData = DataManager::getInstance()->getTeamData();
    log("===%s",json_dumps(teamData, 0));
    this->resetUI();
    //this->request();
    
    return true;
}

void Team2::request()
{
    //json_t* msg=json_object();
    //json_object_set(msg, "token", Manager::getInstance()->psocket->token);
    //Manager::getInstance()->psocket->sendMsg("connector.entryHandler.entry", msg);
}

void Team2::resetUI()
{
    int dataSize=json_array_size(teamData);
    for(int i=0;i<this->items.size();i++){
        Node* item=this->items.at(i);
        Node* lock=item->getChildByName("lock");
        Node* add=item->getChildByName("add");
        Node* card=item->getChildByName("card");
        
        lock->setVisible(false);
        add->setVisible(false);
        card->setVisible(false);
        
        if(i>=dataSize){
            lock->setVisible(true);
            continue;
        }else{
            json_t* data=json_array_get(teamData, i);
            json_t* cards=json_object_get(data, "cards");
            if(cards)log("size:%zu,%s",json_array_size(cards),json_dumps(data, 0));
            //if(cards==NULL || json_array_size(cards)==0 || json_object_get(json_array_get(cards, 0), "xid")==NULL){
            if(cards==NULL || json_array_size(cards)==1){
                add->setVisible(true);
                continue;
            }else{
                card->setVisible(true);
            }
            
            int cardNum=json_array_size(cards);
            for(int i=0;i<4;i++){
                Text* atkTxt=dynamic_cast<Text*>(card->getChildByName("atk"+Value(i).asString()));
                Sprite* typeIcon=dynamic_cast<Sprite*>(card->getChildByName("type"+Value(i).asString()));
                Sprite* atkTypeIcon=dynamic_cast<Sprite*>(card->getChildByName("atkType"+Value(i).asString()));
                atkTxt->setVisible(false);
                atkTypeIcon->setVisible(false);

                if(typeIcon != nullptr){
                    typeIcon->setVisible(false);
                }
                
                json_t* cardData=json_array_get(cards, i);
                
                if(json_object_get(cardData, "xid") == NULL){
                    continue;
                }
                
                if(i<cardNum){
                    int atkNum=json_integer_value(json_object_get(cardData, "atk"));
                    int xid=json_integer_value(json_object_get(cardData, "xid"));
                    atkTxt->setVisible(true);
                    atkTypeIcon->setVisible(true);
                    if(i==0){
                        XGroup* xgroup=XGroup::record(Value(xid));
                        XSkill* xskill=XSkill::record(Value(xgroup->getSkillId()));
                        atkTxt->setString(Value(atkNum).asString());
                        atkTypeIcon->setDisplayFrame(Sprite::createWithSpriteFrameName("atkType"+Value(xskill->getAtkType()).asString()+".png")->displayFrame());
                    }else{
                        XCard* xcard=XCard::record(Value(xid));
                        typeIcon->setVisible(true);
                        atkTxt->setString(Value(atkNum).asString());
                        typeIcon->setDisplayFrame(Sprite::createWithSpriteFrameName("cardType_"+Value(xcard->getCardType()).asString()+".png")->displayFrame());
                        atkTypeIcon->setDisplayFrame(Sprite::createWithSpriteFrameName("atkType"+Value(xcard->getAtkType()).asString()+".png")->displayFrame());
                    }
                   
                }
            }
        }
    }
}

void Team2::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    for(int i=0;i<this->items.size();i++){
        Node* item=this->items.at(i);
        Size size=item->getContentSize();
        Vec2 itemVec=this->ui->convertToWorldSpace(item->getPosition());
        Rect rect=Rect(itemVec.x,itemVec.y,size.width,size.height);
        if(rect.containsPoint(touch->getLocation())){
            json_t* tdata=json_array_get(this->teamData, i);
            if(i >= json_array_size(this->teamData)){
                Manager::getInstance()->showMsg("请先解锁卡组");
                continue;
            }
            TeamCard* card=TeamCard::create(tdata,i);
            card->show(this);
        }
    }
}

void Team2::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000:
        {
            DataManager::getInstance()->setTeamData(this->teamData);
            log("teamdata:%s",json_dumps(DataManager::getInstance()->getTeamData(), 0));
            Manager::getInstance()->switchScence(HomeScene::createScene());
            break;
        }
        case 1001: //tab1
        {
            this->clear(true);
            break;
        }
    }
}

void Team2::initNetEvent(){
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        json_t* msg=(json_t*)event->getUserData();
        const char* route=json_string_value(json_object_get(msg, "route"));
        int msgID=msges[route];
        switch (msgID)
        {
            case GATE_GATEHANDLER_ENTRY:
            {
                break;
            }
            case CONNECTOR_ENTRYHANDLER_ENTRY:
            {
                break;
            }
            default:
                break;
        }

    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
}