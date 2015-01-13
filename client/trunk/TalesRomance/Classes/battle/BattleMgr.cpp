//
//  BattleMgr.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#include "BattleMgr.h"

static BattleMgr* instance=nullptr;

BattleMgr* BattleMgr::getInstance(){
    if(instance==nullptr){
        instance=new BattleMgr();
    }
    return instance;
}

void BattleMgr::init()
{
    auto scene=BattleScene::createScene();
    Manager::getInstance()->switchScence(scene);
    this->view=(BattleScene*)scene->getChildByTag(0);
    this->initNetEvent();
    
    const char* route="";
    json_t* msg=json_object();
    json_object_set(msg, "type", json_integer(1));
    json_object_set(msg, "targetID", json_integer(1001));
    
   //Manager::getInstance()->psocket->sendMsg(route, msg);
    
    log("teamdata:%s",json_dumps(DataManager::getInstance()->getTeamData(), 0));

}

void BattleMgr::init(rapidjson::Value& data)
{
    
}

void BattleMgr::handleResult()
{

}

void BattleMgr::initNetEvent(){
    this->listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        json_t* msg=static_cast<json_t*>(event->getUserData());
        int reqId=json_integer_value(json_object_get(msg, "reqId"));
        switch (reqId)
        {
            case C_BATTLE:
            {
                this->view->startAnimation(msg);
                break;
            }

            default:
                break;
        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    
}

void BattleMgr::clear()
{
    //SpriteFrameCache::getInstance()->removeSpriteFrames();
    Director::getInstance()->getEventDispatcher()->removeEventListener(this->listener);
}