//
//  MFight.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#ifndef __fancyHeart__MFight__
#define __fancyHeart__MFight__

#include <iostream>
#include "cocos2d.h"
#include "external/json/rapidjson.h"
#include "external/json/document.h"
#include "BattleScene.h"

using namespace cocos2d;

class BattleScene;

class BattleMgr:public Ref{
private:
    void initHero(std::vector<long long> heros);
    std::vector<int> getMonsterSkill(int xid);
    std::vector<int> groups;
    
    int gateID;
    int nodeID;

public:
    static BattleMgr* getInstance();
    void init();
    void init(rapidjson::Value& data);
    void startBattle();
    void startBattleAnimEnd();
    void startEndDram();
    void handleResult();
    void stopAllFighter();
    void initNpc();
    
    void pause();
    void resume();
        
    void clearDieNpc(int pos);
    void clear();
    
    BattleScene* view;
    bool isOver;
    int npcNum;
    int heroNum;
    int groupID;
    int winPos;
   
    float heroScale;
};

#endif /* defined(__fancyHeart__MFight__) */
