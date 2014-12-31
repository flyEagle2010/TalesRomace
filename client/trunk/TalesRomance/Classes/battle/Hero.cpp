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
    fPath="skeleton_zhujue.json";
    rPath="zhujue.atlas";
    this->pos=pos;
	//init ui
    float scale=1;
    this->skeletonNode = SkeletonAnimation::createWithFile(fPath, rPath, scale);
    if(this->pos<1){
        this->skeletonNode->setScale(-1,1);
    }else{
        this->skeletonNode->setScale(1,1);
    }
    this->addChild(skeletonNode);
    this->skeletonNode->setCompleteListener(CC_CALLBACK_1(Hero::onAnimationEnd, this));
    this->skeletonNode->setEventListener(CC_CALLBACK_2(Hero::onSkeletonEvent, this));
    //this->skeletonNode->setTimeScale(2);
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

void Hero::attack()
{
    std::string name=type==1?ani_attack1:ani_attack2;
    this->setAnimation(TrackIndex::ANI_ATTACK, name, false);
}

void Hero::attacked(int num)
{
    this->setAnimation(TrackIndex::ANI_ATTACKED ,ani_attacked, false);
    this->skeletonNode->addAnimation(TrackIndex::ANI_COMMON, ani_idle, true);
    
    this->attackedEffect();
    this->hp-=num;
    this->fallHp(num);
    //this->die(pHit);
}

void Hero::attackedEffect()
{
    Clip* clip=Clip::create("hurt_fire2.plist", "hurt_fire2",20);
    this->addChild(clip,2);
    clip->setScale(1.5);
    //spBone* bone=this->skeletonNode->findBone("body");
    //clip->setPosition(Vec2(bone->worldX,bone->worldY+bone->data->length*0.8));
    clip->setPosition(Vec2(0,120));
    clip->play();
}

void Hero::buildup()
{
    this->setAnimation(TrackIndex::ANI_BUILDUP, ani_buildup, false);
    this->buildupAni=SkeletonAnimation::createWithFile("skeleton_juqi_2.json", "juqi_2.atlas");
    this->addChild(buildupAni,-1);
    buildupAni->setAnimation(0, "animation", true);
}

void Hero::jumpIn()
{
    this->setAnimation(TrackIndex::ANI_JUMPIN, ani_jumpIn, false);
}

void Hero::jumpOut()
{
    Spawn* sp=Spawn::create(MoveTo::create(0.2, Vec2(320,640)),SkewBy::create(0.2, 0.2, 0.2), NULL);
    CallFunc* next=CallFunc::create(std::bind(&BattleScene::playRound, BattleMgr::getInstance()->view));
    CallFunc* removeFun=CallFunc::create(std::bind(&Hero::removeFromParent, this));
    this->runAction(Sequence::create(sp,next,removeFun, NULL));
}

void Hero::die(int num)
{
    this->skeletonNode->clearTracks();
    this->skeletonNode->setAnimation(TrackIndex::ANI_DIE, ani_die, false);
    //this->setAnimation(TrackIndex::ANI_DIE, ani_die, false);

    this->fallHp(num);
    
    BattleMgr::getInstance()->view->playEnd();
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
    
    //label->setPosition(this->convertToWorldSpace(Vec2(body->worldX,body->worldY+180)));
    label->setPosition(this->convertToWorldSpace(Vec2(0,240)));
    ScaleTo* scale1=ScaleTo::create(0.15, 0.5);
    
    MoveBy* move=MoveBy::create(0.4, Vec2(0, 80));
    Sequence* sq=Sequence::create(DelayTime::create(0.2),FadeOut::create(0.3), NULL);
    
    Spawn* sp3=Spawn::create(move,sq, NULL);
    CallFunc* cf4=CallFunc::create(CC_CALLBACK_0(Label::removeFromParent, label));
    
    label->runAction(Sequence::create(scale1,DelayTime::create(0.3),sp3,cf4, NULL));

}

void Hero::hitWord()
{
   
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
    if(!strcmp(event->data->name,"attack") && this->type!=1){
        BattleMgr::getInstance()->view->attacked();
    }
    if(trackIndex==TrackIndex::ANI_ATTACKED){

    }
};

void Hero::onAnimationEnd(int trackIndex)
{
    switch (trackIndex) {
        case TrackIndex::ANI_BUILDUP:
        {
            BattleMgr::getInstance()->view->attack();
            BattleMgr::getInstance()->view->black->setVisible(false);
            this->buildupAni->removeFromParent();
            break;
        }
        case TrackIndex::ANI_ATTACK:
        {
            if(BattleMgr::getInstance()->view->isOver){
                if(this->type==1)this->setVisible(false);
                break;
            }
            if(this->type==1){
                this->jumpOut();
                break;
            }
            if(!json_object_get(data, "isAoYi")){
                BattleMgr::getInstance()->view->attack();
            }
            break;
        }
        case TrackIndex::ANI_DIE:
        {
            break;
        }
        case TrackIndex::ANI_WIN:
        {
            BattleMgr::getInstance()->view->showResult();
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
