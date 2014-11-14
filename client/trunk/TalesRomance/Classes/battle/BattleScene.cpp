//
//  BattleScene.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#include "BattleScene.h"
#include "HomeScene.h"

Scene* BattleScene::createScene(){
	auto scene = Scene::create();
    auto layer = BattleScene::create();
    scene->addChild(layer,0,0);
	return scene;
}

BattleScene* BattleScene::create()
{
    BattleScene* pRet=new BattleScene();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BattleScene::init(){

    if(!BaseUI::init("","")){
        return false;
    }

    ui::Button* btn_pause=static_cast<ui::Button*>(top->getChildByName("btn_pause"));
    ui::Button* btn_auto=static_cast<ui::Button*>(skillNode->getChildByName("btn_auto"));
    btn_pause->addTouchEventListener(CC_CALLBACK_2(BattleScene::touchButtonEvent,this));
    btn_auto->addTouchEventListener(CC_CALLBACK_2(BattleScene::touchButtonEvent, this));
    return true;
}

void BattleScene::onEnter()
{
    BaseUI::onEnter();
    this->schedule(SEL_SCHEDULE(&BattleScene::tick), 1);
}

void BattleScene::initNpcIcon(int num)
{

}

void BattleScene::setNpcIcon(int num,bool isKill)
{
 
}

void BattleScene::resetProgress()
{
    
}

void BattleScene::bounceTo(FighterMgr *npc)
{
    
}

void BattleScene::tick(float dt)
{

}

void BattleScene::interceptTouchEvent(Widget::TouchEventType event, Widget *sender, Touch *touch)
{
 
}

void BattleScene::touchButtonEvent(cocos2d::Ref *pSender, Widget::TouchEventType type)
{
    if(type!=TouchEventType::ENDED) return;

}

void BattleScene::initNetEvent()
{
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        NetMsg* msg = static_cast<NetMsg*>(event->getUserData());
        switch (msg->msgId)
        {
            case C_FIGHTRESULT:
            {
//                PResultResp pResultResp;
//                pResultResp.ParseFromArray(msg->bytes, msg->len);
//                GateResult* gateResult=GateResult::create(this, pResultResp);
//                gateResult->show();
                break;
            }
            default:
                break;
        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void BattleScene::onExit()
{
    Node::onExit();
    BattleMgr::getInstance()->clear();
    SpriteFrameCache::getInstance()->removeSpriteFrames();
}