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
    BaseUI::init("Maze.csb", "maze.plist");
    
    this->map = TMXTiledMap::create("tree_block_bottom.tmx");
    this->ui->addChild(map);
    TMXTiledMap* node=dynamic_cast<TMXTiledMap*>(ui->getChildByName("map"));
    //this->map->setPosition(node->getPosition());
    this->map->setPosition(Vec2(153, 36));
    
    this->topLayer=this->map->getLayer("top");
    
    this->goldLabel=(Label*)this->ui->getChildByName("goldLabel");
    this->hpLabel=(Label*)this->ui->getChildByName("hpLabel");
    this->numLabel=(Label*)this->ui->getChildByName("numLabel");
    this->icon=(Sprite*)this->ui->getChildByName("icon");
    this->hpIcon=(Sprite*)this->ui->getChildByName("hpIcon");
    
    Button* btn=(Button*)this->ui->getChildByName("btn_exit");
    btn->addClickEventListener(CC_CALLBACK_1(Maze::clickButtonEvent,this));
    
    this->resetUI();
    
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

void Maze::resetUI()
{
    this->goldLabel->setString(Value(30).asString());
    this->hpLabel->setString(Value(20).asString()+"/"+Value(100).asString());
    this->numLabel->setString(Value(3).asString());
    //this->icon->setDisplayFrame(Sprite::create("")->displayFrame());
    //this->hpIcon->setDisplayFrame(Sprite::create("")->displayFrame());
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
    //TMXObjectGroup* objectGroup=this->map->getObjectGroup("top");
    //ValueMap valueMap=objectGroup->getObject("1");
    
    BattleMgr::getInstance()->init();
    
    return;
    
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

void Maze::clickButtonEvent(Ref* pSender)
{
    Button* btn=(Button*)pSender;
    switch (btn->getTag()) {
        case 5:
            this->clear(true);
            break;
            
        default:
            break;
    }
}

void Maze::initNetEvent()
{
    
}

void Maze::onExit()
{
    BaseUI::onExit();
}