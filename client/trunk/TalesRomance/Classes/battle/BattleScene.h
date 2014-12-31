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

using namespace ui;
using namespace cocos2d;
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
    void startAnimation(json_t* data);

    void attack();
    void buildup();
    void attacked();
    void playRound();
    void cardDispear();
    
    void playBattleCard();
    void petAttack();
    void showBuff(int pos);
    void playEnd();
    void showResult();
    

public:

    bool isOver;
    Sprite* bg;
    Size wsize;
    json_t* data;
    
    Node* bottom;
    Node* heroNode;
    Layout* black;

    Vector<Hero*> heros;
    Vector<Node*> heroInfos;

    Vector<BattleCard*> cards;


};
#endif /* defined(__fancyHeart__BattleScene__) */
