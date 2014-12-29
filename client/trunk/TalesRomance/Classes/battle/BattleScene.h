//
//  BattleScene.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#ifndef __fancyHeart__BattleScene__
#define __fancyHeart__BattleScene__

#include <iostream>
#include "cocos2d.h"
#include "Manager.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "external/json/rapidjson.h"
#include "BattleMgr.h"
#include "Clip.h"
#include "Hero.h"
#include "BattleCard.h"
#include "StandDraw.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
class FData;
class FighterMgr;
class BattleCard;
class Hero;

class BattleScene:public BaseUI{
    int roundIndex;
    int cardIndex;
    json_t* round;
    json_t* item;
    bool isDispear;
    Hero* attacker;
    Hero* defender;
public:
	static Scene* createScene();
    static BattleScene* create();
	virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    virtual void touchButtonEvent(cocos2d::Ref *pSender, Widget::TouchEventType type);
    void attack();
    void buildup();
    void attacked();
    void playRound();
    void cardDispear();
    
    void playBattleCard();
    void petAttack();
    void showBuff(int pos);
    void showResult();
    
    Vector<BattleCard*> BattleCards;
    Size wsize;
    json_t* data;

public:
    Node* heroNode;

    Vector<Node*> heroInfos;
    Vector<Hero*> heros;
    Node* bottom;
    Sprite* bg;
    void startAnimation(json_t* data);

};
#endif /* defined(__fancyHeart__BattleScene__) */
