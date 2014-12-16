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
    }
    
    CC_SAFE_DELETE(pRet);
    
    return nullptr;
}

bool Hero::init(std::string fPath,std::string rPath,int pos)
{
    this->pos=pos;
	//init ui
    float scale=0.7;
    this->skeletonNode = SkeletonAnimation::createWithFile(fPath, rPath, scale);

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

void Hero::attacked(int num)
{
    this->setAnimation(TrackIndex::ANI_ATTACKED ,ani_attacked, false);
    this->skeletonNode->addAnimation(TrackIndex::ANI_COMMON, ani_idle, true);
    
    this->attackedEffect();
    
    //this->die(pHit);
}

void Hero::attackedEffect()
{
    Clip* clip=Clip::create("hurt_fire2.plist", "hurt_fire2",20);
    this->addChild(clip,2);
    spBone* bone=this->skeletonNode->findBone("body");
    clip->setPosition(Vec2(bone->worldX,bone->worldY));
    clip->play();
}

void Hero::buildup()
{
    this->setAnimation(TrackIndex::ANI_COMMON, ani_buildup, false);
}

//void Hero::defence(int num)
//{
//    this->fallHp(num);
//    
//    std::string name="";
//    if(this->skeletonNode->getCurrent()){
//        name=this->skeletonNode->getCurrent()->animation->name;
//    }
//    
//    if(name!= ani_attack && name!=ani_skillAttack1 && name!=ani_skillAttack2 && name!=ani_win){
//        this->setAnimation(TrackIndex::ANI_COMMON, ani_defence, 0);
//        this->skeletonNode->addAnimation(0, ani_idle, true);
//    }
//    Clip* clip=Clip::create("dun.plist", "dun",10);
//    this->addChild(clip,2);
//    if(this->pos>4){
//        clip->setScale(0.5,0.5);
//        clip->setPosition(Vec2(-30,100));
//    }else{
//        clip->setScale(-0.5,0.5);
//        clip->setPosition(Vec2(30,100));
//    }
//    clip->play();
//
//}

void Hero::die(int num)
{
    this->skeletonNode->clearTracks();
    
    this->setAnimation(TrackIndex::ANI_DIE, ani_die, false);

    this->fallHp(num);
    
    BattleResult* result=BattleResult::create();
    result->show((BaseUI*)BattleMgr::getInstance()->view); //show(BattleMgr::getInstance()->view);
}

void Hero::fallHp(int num)
{
    spBone* body=this->skeletonNode->findBone("body");
//    if(phit.isimmune()){
//        return;
//    }
    
//    if(phit.ismiss()){
//        Sprite* miss=Sprite::create("miss.png");
//        BattleMgr::getInstance()->view->addChild(miss);
//        miss->setScale(1.2);
//        miss->setPosition(this->convertToWorldSpace(Vec2(body->worldX,body->worldY+120)));
//        Sequence* seq=Sequence::create(ScaleTo::create(0.2, 0.6),MoveBy::create(0.3, Vec2(0,40)),FadeOut::create(0.3),CallFunc::create(CC_CALLBACK_0(Label::removeFromParent, miss)), NULL);
//        miss->runAction(seq);
//        return;
//    }
    std::string hpFileName=num>0?"num_hp.png":"num_heal.png";
    Label* label;
    label=Label::createWithCharMap(hpFileName, 56, 63, '0');

//    if(phit.iscrh()){
//        label=Label::createWithCharMap("num_hit.png", 84, 95, '0');
//    }else{
//        label=Label::createWithCharMap(hpFileName, 56, 63, '0');
//    }
    
    std::string str=(num>0?";":":")+Value(abs(num)).asString();
    label->setString(str);
    label->setScale(1);
    BattleMgr::getInstance()->view->addChild(label,2);
    
    label->setPosition(this->convertToWorldSpace(Vec2(body->worldX,body->worldY+100)));
    ScaleTo* scale1=ScaleTo::create(0.15, 0.5);
    
    MoveBy* move=MoveBy::create(0.5, Vec2(0, 80));
    Sequence* sq=Sequence::create(DelayTime::create(0.2),FadeOut::create(0.3), NULL);
    
    Spawn* sp3=Spawn::create(move,sq, NULL);
    CallFunc* cf4=CallFunc::create(CC_CALLBACK_0(Label::removeFromParent, label));
    
    label->runAction(Sequence::create(scale1,DelayTime::create(0.3),sp3,cf4, NULL));

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
//        PHit phit;
//        phit.set_hp(200);
//        this->fallHp(phit);
    }
};

void Hero::onAnimationEnd(int trackIndex)
{
    switch (trackIndex) {
            
        case TrackIndex::ANI_ATTACK:
        {
           
            break;
        }
        case TrackIndex::ANI_DIE:
        {
//            Sequence* sq=Sequence::create(DelayTime::create(0.2),FadeOut::create(2.0),CallFunc::create(CC_CALLBACK_0(Hero::dieClear, this)), NULL);
//            this->skeletonNode->runAction(sq);
//            this->stopAllActions();
            break;
        }
        case TrackIndex::ANI_WIN:
        {
            //this->runAction(Sequence::create(DelayTime::create(1.2),CallFunc::create(CC_CALLBACK_0(BattleMgr::startEndDram, BattleMgr::getInstance())), NULL));
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