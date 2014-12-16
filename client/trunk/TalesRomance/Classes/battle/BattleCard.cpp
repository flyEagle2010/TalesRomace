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
    if(!BaseUI::init("BattleCard.csb", "card.plist")){
        return false;
    }
   
    this->ui->setPosition(Vec2(0,0));
    this->ui->setAnchorPoint(Vec2(0,0));
    this->ui->setScale(0.3);
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
    MoveBy* move=MoveBy::create(0.3, Vec2(100*(2-index)+100,0));
    this->runAction(Sequence::create(DelayTime::create(index),Show::create(), NULL));
    this->ui->runAction(Sequence::create(DelayTime::create(index),move,CallFunc::create(CC_CALLBACK_0(BattleCard::startToCenter, this)), NULL));
}

void BattleCard::startToCenter()
{
    ParticleSystem* fapai=ParticleSystemQuad::create("fapai.plist");
    this->addChild(fapai,2);
    fapai->setPosition(this->ui->getPosition());
    fapai->setScale(0.5);
    
    Size size=Size(290,441)*0.8;
    Size wsize=Director::getInstance()->getWinSize();

    Spawn* spaw=Spawn::create(MoveTo::create(0.2, Vec2(wsize.width*0.5+size.width*(1-index),wsize.height*0.5)),ScaleTo::create(0.2,0.75),SkewBy::create(0.2, 0, 30), NULL);
    SkewTo* skew=SkewTo::create(0.2, 0, 0);
    CallFunc* cf=CallFunc::create(CC_CALLBACK_0(BattleCard::useSkill, this));
    this->ui->runAction(Sequence::create(DelayTime::create(0.3),spaw, skew,DelayTime::create(0.8*(groupNum-index)),cf,NULL));
}

void BattleCard::useSkill()
{
    //skilleffect.plist 技能图标亮
    //cardSkillEffect.plist 牌发光
    
    Clip* clip=Clip::create("skillEffect.plist", "skillEffect",12);
    this->addChild(clip);
    clip->setPosition(this->ui->getPosition());
    float duration=clip->play();

    this->runAction(Sequence::create(DelayTime::create(duration),CallFunc::create(std::bind(&BattleCard::playRim, this)), NULL));
  
}

void BattleCard::playRim()
{
    Clip* clip=Clip::create("cardSkillEffect.plist", "cardSkillEffect",12);
    this->addChild(clip);
    clip->setPosition(this->ui->getPosition());
    float duration=clip->play();
    this->runAction(Sequence::create(DelayTime::create(duration+0.3),CallFunc::create(std::bind(&BattleCard::playDispear, this)), NULL));
}

void BattleCard::playDispear()
{
    this->ui->setVisible(false);
    Clip* clip=Clip::create("cardXiaoShi.plist", "cardXiaoShi",12);
    this->addChild(clip);
    clip->setPosition(this->ui->getPosition());
    float duration=clip->play();
    this->runAction(Sequence::create(DelayTime::create(duration),CallFunc::create(std::bind(&BattleCard::playEnd, this)), NULL));

    return;
    
    
    /*
     ParticleSystem* bullet=ParticleSystemQuad::create("ghostB.plist");
     this->addChild(bullet,2);
     this->ui->setVisible(false);
     */
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