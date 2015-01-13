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
        instance->initData();
    }
    return instance;
}

void DataManager::initData()
{
    std::string fullPath=FileUtils::getInstance()->fullPathForFilename("testData.json");
    std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
    json_error_t error;
    this->data=json_loads(str.c_str(), JSON_ENCODE_ANY, &error);
    //log("data:%s",json_dumps(data, 0));
    
    this->setTeamData(json_object_get(this->data, "teams"));
}
