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
#include "BattleResult.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
using namespace spine;

class MFighter;

#define speed 190


class Hero:public Node
{
    
    Sprite* hpBg;
    
    
    SkeletonAnimation* skeletonNode;
    SkeletonAnimation* buildupAni;

    void setAnimation(int trackIndex, std::string animName,bool loop);
    void onFrameEvent(Bone *bone, const std::string& frameEventName, int originFrameIndex, int currentFrameIndex);
    void animationEvent(Armature *armature, MovementEventType movementType, const std::string& movementID);
    void onAnimationEnd(int trackIndex);
    void onSkeletonEvent(int trackIndex,spEvent* event);
    
    void jumpOutOver(TrackIndex index);
public:
    ~Hero(){};
    static Hero* create(std::string fPath,std::string rPath,int pos);
    bool init(std::string fPath,std::string rPath,int pos);
    virtual void onEnter();
    virtual void onExit();
    void stand();
    void run();
    void attack(); //1普通 2射击
    void buildup();
    void attacked(int num);
    void die(int num);
  
    void fallHp(int num);
    void hitWord();
    void revive();
    void playBuffer();
    void win();
    void move(Vec2 vec);
    
    void jumpIn();
    void jumpOut();
    void attackedEffect();
  
public:
    json_t* data;
    int hp;
    int pos;
    int type;
   
};
#endif /* defined(__fancyHeart__Hero__) */
