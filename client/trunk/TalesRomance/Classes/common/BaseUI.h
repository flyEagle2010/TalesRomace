//
//  BaseUI.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-6-12.
//
//

#ifndef __fancyHeart__BaseUI__
#define __fancyHeart__BaseUI__

#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "Manager.h"
#include "Clip.h"
#include "Utils.h"
using namespace cocostudio;

using namespace cocos2d;
using namespace ui;
class BaseUI:public Widget {
public:
    virtual void initNetEvent(){};
    virtual void onDlgClose(rapidjson::Value &data);
    virtual bool init(std::string fileName,std::string resName);
    virtual void show(BaseUI* preUI);
    virtual void clear(bool isDel);
    virtual void onButtonClick(Ref *pSender){};
    virtual void resetUI(){};
    Node* ui;
    
public:
    virtual void onEnter();
    virtual void onExit();
    virtual void reRestUI(){};
public:
    BaseUI* preUI;
};
#endif /* defined(__fancyHeart__BaseUI__) */
