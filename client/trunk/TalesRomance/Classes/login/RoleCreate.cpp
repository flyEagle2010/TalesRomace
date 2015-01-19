//
//  RoleCreate.cpp
//  TalesRomance
//
//  Created by qll on 14/12/18.
//
//

#include "RoleCreate.h"
RoleCreate* RoleCreate::create()
{
    RoleCreate* pRet=new RoleCreate();
    
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool RoleCreate::init()
{
    if(!BaseUI::init("RoleCreate.csb",""))
    {
        return false;
    }
    for(int i=1000;i<1001;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        btn->addClickEventListener(CC_CALLBACK_1(RoleCreate::onButtonClick, this));
    }
    return true;
}

void RoleCreate::resetUI()
{
   
}

void RoleCreate::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    
}

void RoleCreate::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000:
        {
            json_t* msg=json_object();
            json_object_set(msg, "xid", json_integer(1));
            json_object_set(msg, "name", json_string("哇哈哈1"));
            //PomeloSocket::getInstance()->sendMsg("connector.roleHandler.createPlayer", msg);
            PomeloSocket::getInstance()->sendMsg(ROTE_CONNECT_CREATE_PLAYER, msg);
            break;
        }
        case 1001: //tab1
        {
            this->clear(true);
            break;
        }
    }
}

void RoleCreate::initNetEvent(){
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        json_t* msg=(json_t*)event->getUserData();
        int msgID=json_integer_value(json_object_get(msg, "msgID"));
        switch (msgID)
        {
            case C_CREATE_ROLE:
            {
                int code =json_integer_value(json_object_get(msg, "code"));
                if(code==200){
                    //PomeloSocket::getInstance()->sendMsg("room.playerHandler.entry", json_object());
                    PomeloSocket::getInstance()->sendMsg(ROTE_CONNECT_CREATE_PLAYER, json_object());
                }
                break;
            }
            case C_ROOM_ENTRY:
            {
                DataManager::getInstance()->setRoleData(msg);
                Scene* home=HomeScene::createScene();
                Manager::getInstance()->switchScence(home);
                break;
            }
            default:
                break;
        }
        
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
}