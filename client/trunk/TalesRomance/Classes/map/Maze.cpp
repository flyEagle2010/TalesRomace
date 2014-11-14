//
//  Map.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/11.
//
//

#include "Maze.h"

Maze* Maze::create()
{
    Maze* pRet=new Maze();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Maze::init()
{
    BaseUI::init("Layer.csb", "tree_block.plist");
    this->map = TMXTiledMap::create("res/tree_block_bottom.tmx");
    addChild(map, 0);
    Size wsize=Director::getInstance()->getWinSize();
    Size mapSize=this->map->getContentSize();
    this->map->setPosition(Vec2((wsize.width-mapSize.width)/2.0,(wsize.height-mapSize.height)/2.0));
    
    this->topLayer=this->map->getLayer("top");
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {return true;};
    listener->onTouchEnded = CC_CALLBACK_2(Maze::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void Maze::onEnter()
{
    BaseUI::onEnter();
 
}

Vec2 Maze::position2Grid(Vec2 position)
{
    int x = (position.x-map->getPositionX()) / map->getTileSize().width;
    int y =((map->getMapSize().height * map->getTileSize().height) - position.y+map->getPositionY()) / map->getTileSize().height;
    return Vec2(x, y);
}

void Maze::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
    Vec2 grid=this->position2Grid(touch->getLocation());
    Sprite* sprite=this->topLayer->getTileAt(grid);
    if(sprite){
        this->topLayer->removeTileAt(grid);
    }
    TMXObjectGroup* objectGroup=this->map->getObjectGroup("top");
    ValueMap valueMap=objectGroup->getObject("1");
    
    //int tileGrid=this->topLayer->getTileGIDAt(grid);
    int itemType=6;
    switch (itemType) {
        case MazeItem::None:
            break;
        case MazeItem::Gold:
            break;
        case MazeItem::Bag:
            break;
        case MazeItem::Hp:
            break;
        case MazeItem::Trap:
            break;
        case MazeItem::Key:
            break;
        case MazeItem::Monster:
        {
            BattleMgr::getInstance()->init();
            break;
        }
        case MazeItem::Transport:
            break;
        default:
            break;
    }
}

void Maze::touchButtonEvent(Ref* pSender, TouchEventType type)
{
    
}

void Maze::initNetEvent()
{
    
}

void Maze::onExit()
{
    BaseUI::onExit();
}