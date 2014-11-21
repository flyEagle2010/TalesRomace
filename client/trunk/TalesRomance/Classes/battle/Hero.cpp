//
//  Hero.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#include "Hero.h"
#include "BattleScene.h"


Hero* Hero::create(std::string fPath,std::string rPath,int pos)
{
    Hero* pRet = new Hero();
    if (pRet && pRet->init(fPath,rPath,pos))
    {
        pRet->autorelease();
        return pRet;
    }else{
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool Hero::init(std::string fPath,std::string rPath,int pos)
{
    this->pos=pos;
	//init ui
    float scale=fPath=="huLi.json"?0.25:0.5;
    this->skeletonNode = SkeletonAnimation::createWithFile(fPath, rPath, 0.5);

    if(this->pos<1){
        this->skeletonNode->setScale(-1,1);
    }else{
        this->skeletonNode->setScale(1,1);
    }
    this->addChild(skeletonNode);
    this->skeletonNode->setEndListener(CC_CALLBACK_1(Hero::onAnimationEnd, this));
    this->skeletonNode->setEventListener(CC_CALLBACK_2(Hero::onSkeletonEvent, this));
 
	return true;
}

void Hero::onEnter()
{
    Node::onEnter();
    this->stand();
}

void Hero::stand()
{
    this->setAnimation(TrackIndex::ANI_COMMON, ani_idle, true);
}

void Hero::run()
{
    if(this->getActionByTag(ACTION_RUN_TAG)){
        this->stopActionByTag(ACTION_RUN_TAG);
    }
    Vec2 vec(pos>4?-1100:1100,0);
    MoveBy* move=MoveBy::create(5, vec);
    move->setTag(ACTION_RUN_TAG);
    this->runAction(move);
    this->setAnimation(TrackIndex::ANI_COMMON, ani_walk, true);
}

void Hero::move(Vec2 vec)
{
    MoveBy* move=MoveBy::create(0.2, vec);
    this->runAction(move);
}

void Hero::attack(std::string actionName)
{
    this->setAnimation(TrackIndex::ANI_ATTACK, actionName, false);
    this->skeletonNode->addAnimation(TrackIndex::ANI_COMMON, ani_idle, true);
}

void Hero::attacked(PHit& pHit)
{
//    this->fallHp(pHit);
    this->setAnimation(TrackIndex::ANI_ATTACKED ,ani_attacked, false);
    this->skeletonNode->addAnimation(TrackIndex::ANI_COMMON, ani_idle, true);
    
    this->attackedEffect();
}

void Hero::attackedEffect()
{
    Clip* clip=Clip::create("hurt_fire2.plist", "hurt_fire2",20);
    this->addChild(clip,2);
    //Vec2 pos=Vec2(this->skeletonNode->convertToWorldSpace(Vec2(bone->worldX,bone->worldY)));

    spBone* bone=this->skeletonNode->findBone("body");
    clip->setPosition(Vec2(bone->worldX,bone->worldY));
    clip->play();
}

void Hero::spell(std::string actionName)
{
    this->setAnimation(TrackIndex::ANI_COMMON, ani_spell, false);
}

void Hero::defence(PHit& pHit)
{
    this->fallHp(pHit);
    
    std::string name="";
    if(this->skeletonNode->getCurrent()){
        name=this->skeletonNode->getCurrent()->animation->name;
    }
    
    if(name!= ani_attack && name!=ani_skillAttack1 && name!=ani_skillAttack2 && name!=ani_win){
        this->setAnimation(TrackIndex::ANI_COMMON, ani_defence, 0);
        this->skeletonNode->addAnimation(0, ani_idle, true);
    }
    Clip* clip=Clip::create("dun.plist", "dun",10);
    //clip->setPosition(this->getPosition()+Vec2(0,60));
    //BattleMgr::getInstance()->view->addChild(clip,2);
    this->addChild(clip,2);
    if(this->pos>4){
        clip->setScale(0.5,0.5);
        clip->setPosition(Vec2(-30,100));
    }else{
        clip->setScale(-0.5,0.5);
        clip->setPosition(Vec2(30,100));
    }
    clip->play();

}

void Hero::die(PHit& pHit)
{
    this->skeletonNode->clearTracks();
    
    this->setAnimation(TrackIndex::ANI_DIE, ani_die, false);

    this->fallHp(pHit);
    
    this->stopActionByTag(ACTION_RUN_TAG);
    this->stopActionByTag(ACTION_SHOOT_TAG);
    
    BattleMgr::getInstance()->view->heroNode->reorderChild(this, 0);
}

void Hero::dieClear()
{
    BattleMgr::getInstance()->clearDieNpc(pos);
}

void Hero::fallHp(PHit& phit)
{
    spBone* body=this->skeletonNode->findBone("body");
//    if(phit.isimmune()){
//        return;
//    }
    
    if(phit.ismiss()){
        Sprite* miss=Sprite::create("miss.png");
        BattleMgr::getInstance()->view->addChild(miss);
        miss->setScale(1.2);
        miss->setPosition(this->convertToWorldSpace(Vec2(body->worldX,body->worldY+120)));
        Sequence* seq=Sequence::create(ScaleTo::create(0.2, 0.6),MoveBy::create(0.3, Vec2(0,40)),FadeOut::create(0.3),CallFunc::create(CC_CALLBACK_0(Label::removeFromParent, miss)), NULL);
        miss->runAction(seq);
        return;
    }
    std::string hpFileName=phit.hp()>0?"num_hp.png":"num_heal.png";
    Label* label;
    if(phit.iscrh()){
        label=Label::createWithCharMap("num_hit.png", 84, 95, '0');
    }else{
        label=Label::createWithCharMap(hpFileName, 56, 63, '0');
    }
    
    std::string str=(phit.hp()>0?";":":")+Value(abs(phit.hp())).asString();
    label->setString(str);
    label->setScale(1);
    BattleMgr::getInstance()->view->addChild(label,2);
//    this->addChild(label);
    //Vec2 pos=this->skeletonNode->getPosition();
    label->setPosition(this->convertToWorldSpace(Vec2(body->worldX,body->worldY+100)));
    ScaleTo* scale1=ScaleTo::create(0.15, 0.5);
    
    MoveBy* move=MoveBy::create(0.5, Vec2(0, 80));
    Sequence* sq=Sequence::create(DelayTime::create(0.2),FadeOut::create(0.3), NULL);
    
    Spawn* sp3=Spawn::create(move,sq, NULL);
    CallFunc* cf4=CallFunc::create(CC_CALLBACK_0(Label::removeFromParent, label));
    
    label->runAction(Sequence::create(scale1,DelayTime::create(0.3),sp3,cf4, NULL));

    //this->hpBar->runAction(ProgressTo::create(0.3, phit.perhp()));
}

void Hero::hitWord()
{
   
}

void Hero::revive()
{
    this->stopActionByTag(HERO_DIE_TAG);
}

void Hero::win()
{
    this->setAnimation(TrackIndex::ANI_WIN, ani_win, false);
}

void Hero::setAnimation(int trackIndex, std::string animName ,bool loop)
{
    this->skeletonNode->setToSetupPose();
    this->skeletonNode->setAnimation(trackIndex, animName, loop);
}

void Hero::onSkeletonEvent(int trackIndex, spEvent* event)
{
    log("%d event: %s, %d, %f, %s", trackIndex, event->data->name, event->intValue, event->floatValue, event->stringValue);
    if(trackIndex==TrackIndex::ANI_ATTACK){
        BattleMgr::getInstance()->view->attacked();
    }
    if(trackIndex==TrackIndex::ANI_ATTACKED){
        PHit phit;
        phit.set_hp(200);
        this->fallHp(phit);
    }
};

void Hero::onAnimationEnd(int trackIndex)
{
    switch (trackIndex) {
        case TrackIndex::ANI_DIE:
        {
            Sequence* sq=Sequence::create(DelayTime::create(0.2),FadeOut::create(2.0),CallFunc::create(CC_CALLBACK_0(Hero::dieClear, this)), NULL);
            this->skeletonNode->runAction(sq);
            this->stopAllActions();
            break;
        }
        case TrackIndex::ANI_WIN:
        {
            BattleMgr::getInstance()->winPos=this->pos;
            this->runAction(Sequence::create(DelayTime::create(1.2),CallFunc::create(CC_CALLBACK_0(BattleMgr::startEndDram, BattleMgr::getInstance())), NULL));
            break;
        }
        default:
            break;
    }
}

void Hero::onExit()
{
    Node::onExit();
}