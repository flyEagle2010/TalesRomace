//
//  Hero.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#ifndef __fancyHeart__Hero__
#define __fancyHeart__Hero__

#include <iostream>
#include "cocos2d.h"
#include "Manager.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "fight.pb.h"
#include "BezierMove.h"
#include <spine/spine-cocos2dx.h>
#include "fconfig.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
using namespace spine;

class MFighter;
#define ani_idle "idle"
#define ani_walk "walk"
#define ani_attacked "attacked"
#define ani_onAir "onAir"
#define ani_onAirFall "onAirFall"
#define ani_onAirAttacked "onAirAttacked"
#define ani_defence "defence"
#define ani_die "die"
#define ani_spell "spell"
#define ani_attack "attack"
#define ani_skillAttack1 "skillAttack1"
#define ani_skillAttack2 "skillAttack2"
#define ani_win "win"

#define speed 190


class Hero:public Node
{
public:

    static Hero* create(std::string fPath,std::string rPath,int pos);
    bool init(std::string fPath,std::string rPath,int pos);
    virtual void onEnter();
    virtual void onExit();
    void stand();
    void run();
    void attack(std::string actionName); //1普通 2射击
    void skillAttak();
    void spell(std::string actionName);
    void attacked(PHit& pHit);
    void die(PHit& hit);
    void defence(PHit& hit);
  
    void fallHp(PHit& phit);
    void hitWord();
    void dieClear();
    void revive();
    void playBuffer();
    void win();
    void move(Vec2 vec);
    
    void attackedEffect();
    
    int pos;
    SkeletonAnimation* skeletonNode;


private:
    Sprite* hpBg;

    void setAnimation(int trackIndex, std::string animName,bool loop);
    void tick(float dt);
    void onFrameEvent(Bone *bone, const std::string& frameEventName, int originFrameIndex, int currentFrameIndex);
    void animationEvent(Armature *armature, MovementEventType movementType, const std::string& movementID);
    void onAnimationEnd(int trackIndex);
};
#endif /* defined(__fancyHeart__Hero__) */
