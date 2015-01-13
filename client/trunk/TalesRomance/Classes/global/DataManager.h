//
//  DataManager.h
//  TalesRomance
//
//  Created by qll on 14/12/8.
//
//

#ifndef __TalesRomance__DataManager__
#define __TalesRomance__DataManager__

#include <stdio.h>
#include "cocos2d.h"
#include "pomelo.h"

using namespace cocos2d;

class DataManager : public Ref {
    CC_SYNTHESIZE(json_t*, teamData, TeamData);
    json_t* data;
    void initData();

public:
    static DataManager* getInstance();
//    json_t* getTeam();
//    void setTeam();
};

#endif /* defined(__TalesRomance__DataManager__) */
