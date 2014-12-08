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
using namespace cocos2d;

class DataManager : public Ref {
    
    
public:
    static DataManager* getInstance();
    
};

#endif /* defined(__TalesRomance__DataManager__) */
