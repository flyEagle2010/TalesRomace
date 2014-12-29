//
//  HomeScene.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-12.
//
//

#include "HomeScene.h"
Scene* HomeScene::createScene(){
	auto scene = Scene::create();
    auto layer = HomeScene::create();
    scene->addChild(layer);
	return scene;
}

HomeScene* HomeScene::create()
{
    HomeScene* homeScene=new HomeScene();
    if (homeScene && homeScene->init("MainScene.csb","home.plist"))
    {
        homeScene->autorelease();
        return homeScene;
    }
    CC_SAFE_DELETE(homeScene);
    return nullptr;
}

bool HomeScene::init(std::string fileName,std::string resName)
{
	if(!BaseUI::init(fileName,resName))
    {
		return false;
	}
    this->top=dynamic_cast<Widget*>(this->ui->getChildByName("top"));
    this->bottom=dynamic_cast<Widget*>(this->ui->getChildByName("bottom"));
    
    for(int i=0;i<7;i++){
        Widget* widget=dynamic_cast<Widget*>(this->bottom->getChildByTag(100+i));
        widget->addTouchEventListener(CC_CALLBACK_2(HomeScene::touchButtonEvent,this));
    }
    
    this->initUi();
//    Sprite* sprite=Sprite::create("cardTest.png");
//    this->addChild(sprite);
//    sprite->setPosition(Vec2(568,320));
//    sprite->setScale(0.75);

	return true;
}

void HomeScene::onEnter()
{
    BaseUI::onEnter();
}

void HomeScene::initUi()
{

}

void HomeScene::intAnimation()
{
    
}

void HomeScene::touchButtonEvent(cocos2d::Ref *pSender, TouchEventType type)
{
    auto sprite=static_cast<Sprite*>(pSender);
  
    if(type==TouchEventType::BEGAN){
        sprite->stopAllActions();
        sprite->runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.15, 1),NULL) );
    }
       
    if(type!=TouchEventType::ENDED){
        return;
    }

    switch (sprite->getTag())
    {
        case 100: //属性
        {
//            GateInfo* gate=GateInfo::create();
//            gate->show(this,1);
            break;
        }
        case 101: //日程
        {
            //MapScene* mapScene=MapScene::create();
            //mapScene->show(this,1);
            Manager::getInstance()->switchScence(MapScene::createScene());
            break;
        }
        case 102: //道具
        {                
            break;
        }
        case 103: //组队
        {
            Team* team=Team::create();
            team->show(this,1);
            break;
        }
        case 104: //卡牌
        {
            break;
        }
        case 105: //邮件
        {
            break;
        }
        case 106: //购物
        {
//          RoleList* roleList = RoleList::create();
//          roleList->show();
            break;
        }
        default:
            break;
    }
}

void HomeScene::initNetEvent()
{
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event)
    {
        NetMsg* msg = static_cast<NetMsg*>(event->getUserData());
        log("Custom event 1 received:%d,%d",msg->msgId,msg->len);
//        switch (msg->msgId)
//        {
//            case C_UPROLE:
//            {
//                this->initUi();
////                LoginResp pm;
////                pm.ParseFromArray(msg->bytes, msg->len);
//            }
//                break;
//            default:
//                break;
//        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void HomeScene::onExit()
{
    BaseUI::onExit();
    this->removeAllChildrenWithCleanup(true);
    Director::getInstance()->getTextureCache()->removeAllTextures();
}
