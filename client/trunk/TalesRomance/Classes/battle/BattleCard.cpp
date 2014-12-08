//
//  BattleCard.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#include "BattleCard.h"

BattleCard* BattleCard::create(int index)
{
    BattleCard* pRet=new BattleCard();
    if(pRet && pRet->init()){
        pRet->index=index;
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BattleCard::init()
{
    if(!BaseUI::init("Card.csb", "")){
        return false;
    }
   
    this->ui->setPosition(Vec2(0,0));
    this->ui->setAnchorPoint(Vec2(0,0));
    return true;
}

void BattleCard::reset(int index, int groupNum, cocos2d::Value data)
{
    this->index=index;
    this->groupNum=groupNum;
    this->data=data;
}

void BattleCard::move()
{
    Size wsize=Director::getInstance()->getWinSize();

    MoveBy* move=MoveBy::create(0.3, Vec2(100*(2-index)+100,0));
    Spawn* spaw=Spawn::create(MoveTo::create(0.3, Vec2(wsize.width*0.5+200*(1-index),wsize.height*0.5)),ScaleTo::create(0.3,1.5),SkewBy::create(0.3, 0, 30), NULL);
    SkewTo* skew=SkewTo::create(0.2, 0, 0);
    CallFunc* cf=CallFunc::create(CC_CALLBACK_0(BattleCard::useSkill, this));
    this->runAction(Sequence::create(DelayTime::create(index*0.3),Show::create(),move,DelayTime::create(0.2),spaw, skew,DelayTime::create(0.8*(groupNum-index)),cf,NULL));
}

void BattleCard::useSkill()
{
    this->ui->setVisible(false);
    Clip* clip=Clip::create("kpps.plist", "kpps",12);
    this->addChild(clip);
    clip->setScale(3);
    float duration=clip->play();
    
    Vec2 end=BattleMgr::getInstance()->view->hero->getPosition()+Vec2(0,150);
    CallFunc* cf=CallFunc::create(std::bind(&BattleCard::playEnd, this));
    this->runAction(Sequence::create(Spawn::create(ScaleTo::create(duration, 0),MoveTo::create(duration, end),NULL),DelayTime::create(0.5),cf, NULL));
}

void BattleCard::playEnd()
{
    if(this->index==groupNum-1){
        BattleMgr::getInstance()->view->attack();
    }
    
    this->removeFromParent();
}

void BattleCard::mergeToHero()
{
    Spawn* sp=Spawn::create(MoveTo::create(0.5, Vec2(400,450)),ScaleTo::create(0.5, 0), NULL);
    Sequence* sq=Sequence::create(sp,CallFunc::create(CC_CALLBACK_0(BattleCard::removeFromParent, this)), NULL);
    this->runAction(sq);
}