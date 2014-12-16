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
    void initNetEvent();
    
    EventListenerCustom* listener;
    std::vector<int> groups;
    int gateID;
    int nodeID;

public:
    static BattleMgr* getInstance();
    void init();
    void init(rapidjson::Value& data);
  
    void handleResult();

    void clear();
    
    BattleScene* view;
};

#endif /* defined(__fancyHeart__MFight__) */
