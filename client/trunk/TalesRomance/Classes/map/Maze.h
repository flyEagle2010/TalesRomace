//
//  Map.h
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/11.
//
//

#ifndef __TalesRomance__Map__
#define __TalesRomance__Map__

#include <stdio.h>
#include "cocos2d.h"
#include "BaseUI.h"
#include "BattleMgr.h"

using namespace ui;
using namespace cocos2d;

enum MazeItem{
    None,       //1啥都没有，即初始状态的图片消失，显示底下的房间底图
    Gold,       //2发现钱币，即初始状态的图片消失，替换为钱币图标，点击钱币可获得游戏币，有多个钱币图标，以表示可获得的游戏币的多寡。
    Bag,        //3发现宝箱，即初始状态的图片消失，替换为宝箱图标，打开宝箱获得道具，有多个宝箱图标，以表示可获得的游戏币的多寡。
    Hp,         //4发现血瓶，即初始状态的图片消失，替换为血瓶图标，点击血瓶增加玩家的当前生命
    Trap,       //5踩到陷阱，即初始状态的图片消失，替换为陷阱图标，并播放陷阱特效。可直接扣除玩家当前生命，或以陷阱为中心对相邻的处于封印状态的格子造成影响。
    Key,        //6发现钥匙，点击钥匙即可打开终点的大门
    Monster,    //7遇到怪物，进入战斗界面，注意！战斗时的玩家生命将继承玩家在探索时的生命值。
    Transport   //8传送，即将玩家从当前房间传送到另一个房间。
};

class Maze : public BaseUI{
    
public:
    static Maze* create();
    virtual void onEnter();
    virtual void onExit();
    virtual bool init();
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
private:
    void initNetEvent();
    void touchButtonEvent(Ref* pSender, TouchEventType type);
    
    Vec2 position2Grid(Vec2 position);

private:
    TMXTiledMap* map;
    TMXLayer* topLayer;
};
#endif /* defined(__TalesRomance__Map__) */
