//
//  MapScene.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/11.
//
//

#include "MapScene.h"

MapScene* MapScene::create()
{
    MapScene* pRet=new MapScene();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool MapScene::init()
{
    if(!BaseUI::init("MapScene.csb", "map.plist")){
        return false;
    }
    
    Size wsize=Director::getInstance()->getWinSize();
    for(int i=1000;i<1003;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        Size size=btn->getContentSize();
        btn->setPosition(Vec2(wsize.width-size.width*0.5+141,btn->getPositionY()));
        btn->addClickEventListener(CC_CALLBACK_1(MapScene::onButtonClick, this));
    }
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {return true;};
    listener->onTouchEnded = CC_CALLBACK_2(MapScene::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->resetUI();
    
    return true;
}

void MapScene::resetUI()
{
    
    this->scrollView=(ScrollView*)this->ui->getChildByName("scrollView");
    //this->scrollView->setPosition(Vec2(141,0));
    Sprite* bg=Sprite::create("mapGate1.png");
    bg->setAnchorPoint(Vec2(0, 0));
    this->scrollView->addChild(bg);
    this->scrollView->setInnerContainerSize(Size(bg->getContentSize().width,640));
    std::vector<int> arr={10,11,12,13,14,15,16,17,18,19};
    for(int i=0;i<arr.size();i++){
        XMap* xmap=XMap::record(Value(arr[i]));
        Sprite* sprite=Sprite::create("mapGateNew.png");
        this->scrollView->addChild(sprite);
        Vec2 pos=PointFromString(xmap->getPos());
        pos=Vec2(pos.x,640-pos.y);
        sprite->setPosition(pos);
    }
}

void MapScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
//    for(int i=0;i<this->groups.size();i++){
//        Node* item=this->groups.at(i);
//        Vec2 position=item->getPosition();
//        Size size=item->getContentSize();
//        Rect rect=Rect(position.x-size.width*0.5,position.y-size.height*0.5,size.width,size.height);
//        item->setVisible(rect.containsPoint(touch->getLocation()));
//    }
}

void MapScene::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000: //退出
        {
            break;
        }
        case 1001: //挑战
        {
            break;
        }
        case 1002: //返回
        {
            this->clear(true);
            break;
        }
    }
}