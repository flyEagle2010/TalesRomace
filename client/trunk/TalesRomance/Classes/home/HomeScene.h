//
//  HomeScene.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-12.
//
//

#ifndef __fancyHeart__HomeScene__
#define __fancyHeart__HomeScene__

#include <iostream>
#include "cocos2d.h"
#include "Manager.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "CircleMove.h"
#include "Clip.h"

#include "Maze.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

class HomeScene:public BaseUI
{
public:
	static Scene* createScene();
    static HomeScene* create();
    virtual void onEnter();
    virtual void onExit();
	virtual bool init(std::string fileName,std::string resName);
    void initUi();

private:
    void initNetEvent();
    void intAnimation();
    void touchButtonEvent(Ref* pSender, TouchEventType type);

    //void onClick(Ref *pSender);
    //void touchButtonEvent(Ref *pSender, TouchEventType type);
    //void touchIconEvent(Ref *pSender, TouchEventType type);
    
    Widget* top;
    Widget* bottom;
    
};

#endif /* defined(__fancyHeart__HomeScene__) */
