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

    
    //this->initHero(heros);
    //this->heroNum=heros.size();
    this->groupID=this->groups.at(0);

}

void BattleMgr::init(rapidjson::Value& data)
{
    
}

void BattleMgr::startBattle()
{
    this->isOver=false;
    this->view->ui->runAction(Sequence::create(FadeOut::create(0.8),FadeIn::create(0.8),CallFunc::create(CC_CALLBACK_0(BattleMgr::startBattleAnimEnd, this)) ,NULL));
}

void BattleMgr::startBattleAnimEnd()
{
    this->view->resume();
    this->groupID=this->groups.at(0);
    this->groups.erase(groups.begin());
    this->initNpc();
    

}

void BattleMgr::initHero(std::vector<long long> npcs)
{
    
}

void BattleMgr::initNpc()
{

}

std::vector<int> BattleMgr::getMonsterSkill(int xid)
{
    std::vector<int> skills;
  
    return skills;
}

void BattleMgr::stopAllFighter()
{
}

void BattleMgr::startEndDram()
{
    this->isOver=true;
}

void BattleMgr::handleResult()
{

}
//超时失败
void BattleMgr::overTime()
{
    this->stopAllFighter();
    PResultReq pResultReq;
    pResultReq.set_gateid(this->gateID);
    pResultReq.set_xid(this->nodeID);
    pResultReq.set_star(0);
    Manager::getInstance()->socket->send(C_FIGHTRESULT, &pResultReq);
}

void BattleMgr::clearDieNpc(int pos)
{

}

void BattleMgr::pause()
{

}

void BattleMgr::resume()
{
 
}

void BattleMgr::clear()
{
    SpriteFrameCache::getInstance()->removeSpriteFrames();
}