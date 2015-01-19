//
//  MapScene.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/11/11.
//
//

#include "MapScene.h"

Scene* MapScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MapScene::create();
    scene->addChild(layer);
    return scene;
}

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
    this->ui->setAnchorPoint(Vec2(0,0));
    this->ui->setPosition(Vec2(0,0));
    
    
    Size wsize=Director::getInstance()->getWinSize();
    for(int i=1000;i<1003;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        Size size=btn->getContentSize();
        btn->setPosition(Vec2(wsize.width-size.width*0.5,btn->getPositionY()));
        btn->addClickEventListener(CC_CALLBACK_1(MapScene::onButtonClick, this));
    }
    
    this->resetUI();
    
//    PomeloSocket::getInstance()->sendMsg(ROTE_ROOM_MAP_LIST, json_object());
    
    return true;
}

void MapScene::resetUI()
{
    this->scrollView=(ui::ScrollView*)this->ui->getChildByName("scrollView");

    Size wsize=Director::getInstance()->getWinSize();

    Sprite* bg=Sprite::create("mapGate1.png");
    bg->setAnchorPoint(Vec2(0, 0));
    this->scrollView->addChild(bg);
    this->scrollView->setInnerContainerSize(Size(bg->getContentSize().width,640));
    this->scrollView->setContentSize(wsize);
    std::vector<int> arr={10,11,12,13,14,15,16,17,18,19};
    for(int i=0;i<arr.size();i++){
        XMap* xmap=XMap::record(Value(arr[i]));
        Sprite* sprite=Sprite::create("mapGateNew.png");
        ImageButton* btn=ImageButton::create(sprite);
        this->scrollView->addChild(btn);
        Vec2 pos=PointFromString(xmap->getPos());
        pos=Vec2(pos.x,640-pos.y);
        btn->setPosition(pos);
        btn->setTag(xmap->getId());
        btn->touchEnd=CC_CALLBACK_1(MapScene::onTouchEnded, this);
    }
}

void MapScene::onTouchEnded(Widget* pSender)
{
    int gateID=pSender->getTag();
    GateInfo* gateInfo=GateInfo::create(gateID);
    gateInfo->show(this);
}

void MapScene::onButtonClick(cocos2d::Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000: //退出
        {
            Manager::getInstance()->switchScence(HomeScene::createScene());
            break;
        }
        case 1001: //挑战
        {
            break;
        }
        case 1002: //返回
        {
            Manager::getInstance()->switchScence(HomeScene::createScene());
            break;
        }
    }
}

void MapScene::initNetEvent(){
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        json_t* msg=(json_t*)event->getUserData();
        int msgID=json_integer_value(json_object_get(msg, "msgID"));
        switch (msgID)
        {
            case C_MAP_LIST:
            {
                json_t* items=json_object_get(msg, "items");
                PomeloSocket::getInstance()->sendMsg(ROTE_ROOM_NODE_LIST, json_array_get(items, 0));
                break;
            }
            case C_NODE_LIST:
            {
                this->jnodes=json_object_get(msg, "items");
                break;
            }
            default:
                break;
        }
        
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
}