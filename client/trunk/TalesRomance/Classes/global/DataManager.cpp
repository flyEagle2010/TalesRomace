//
//  DataManager.cpp
//  TalesRomance
//
//  Created by qll on 14/12/8.
//
//

#include "DataManager.h"
static DataManager* instance=nullptr;

DataManager* DataManager::getInstance()
{
    if(instance==nullptr){
        instance=new DataManager();
    }
    return instance;
}
