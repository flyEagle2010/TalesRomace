//
//  Card.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#include "Card.h"

Card* Card::create(int index)
{
    Card* pRet=new Card();
    if(pRet && pRet->init()){
        pRet->index=index;
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Card::init()
{
    if(!BaseUI::init("Card.csb", "")){
        return false;
    }
    this->ui->setAnchorPoint(Vec2(0.5,0.5));
    return true;
}

void Card::move(float delay)
{
    Size wsize=Director::getInstance()->getWinSize();
    Spawn* sp=Spawn::create(MoveTo::create(0.3, Vec2(wsize.width/2+(index-1)*150,wsize.height/2)),ScaleTo::create(0.3, 0.6), NULL);
    
    Repeat* rp= Repeat::create(RotateBy::create(0.2, 360), 3);
    
    Spawn* sp2=Spawn::create(MoveTo::create(0.5, Vec2(400,450)),ScaleTo::create(0.5, 0), NULL);
    Sequence* sq2=Sequence::create(sp2,CallFunc::create(CC_CALLBACK_0(Card::removeFromParent, this)), NULL);

    this->runAction(Sequence::create(DelayTime::create(delay),sp,rp,sq2,nullptr));
}

void Card::useSkill()
{
    this->ui->setScale(0.2);
    Clip* clip=Clip::create("posui.plist", "posui",5);
    this->addChild(clip);
    clip->setScale(3);
    float duration=clip->play();
    
    this->runAction(Sequence::create(DelayTime::create(duration),MoveTo::create(0.2, Vec2(300,400)), NULL));
}

void Card::mergeToHero()
{
    Spawn* sp=Spawn::create(MoveTo::create(0.5, Vec2(400,450)),ScaleTo::create(0.5, 0), NULL);
    Sequence* sq=Sequence::create(sp,CallFunc::create(CC_CALLBACK_0(Card::removeFromParent, this)), NULL);
    this->runAction(sq);
}