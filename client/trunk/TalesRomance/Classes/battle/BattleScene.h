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
#include "Card.h"
#include "StandDraw.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
class FData;
class FighterMgr;
class Card;
class BattleScene:public BaseUI{
public:
	static Scene* createScene();
    static BattleScene* create();
	virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    virtual void touchButtonEvent(cocos2d::Ref *pSender, Widget::TouchEventType type);
    
    void attack();
    void attacked();
private:
    void startAnimation();
    void initHero();
    void playRound();
    
    void playCard();
    void petAttack();
    

    Vector<Card*> cards;
    Size wsize;
public:
    Node* heroNode;
    Node* heroInfo1;
    Node* heroInfo2;
    Node* title;
    Node* bottom;
    Sprite* bg;
    Hero* hero;
    Hero* npc;
    Hero* pet;
};
#endif /* defined(__fancyHeart__BattleScene__) */
