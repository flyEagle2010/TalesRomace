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
    
    for(int i=0;i<10;i++){
        Widget* widget=dynamic_cast<Widget*>(this->bottom->getChildByTag(100+i));
        if(i==7) widget=dynamic_cast<Widget*>(this->top->getChildByTag(100+i));
        if(i==9) widget=dynamic_cast<Widget*>(this->ui->getChildByTag(100+i));
        if(i==8) {
            widget=dynamic_cast<Widget*>(this->ui->getChildByTag(100+i));
            Size size=widget->getContentSize();
            Size wsize=Director::getInstance()->getWinSize();
            widget->setPosition(Vec2(wsize.width-size.width*0.5,widget->getPositionY()));
        }
        widget->addTouchEventListener(CC_CALLBACK_2(HomeScene::touchButtonEvent,this));
    }

    
    this->initUi();

	return true;
}

void HomeScene::onEnter()
{
    BaseUI::onEnter();
}

void HomeScene::initUi()
{
    LuoLi* luoLi=LuoLi::create();
    this->ui->getChildByName("zhujue")->addChild(luoLi);
    luoLi->setPosition(Vec2(200,0));
}

void HomeScene::intAnimation()
{
    
}

void HomeScene::touchButtonEvent(cocos2d::Ref *pSender, TouchEventType type)
{
    auto sprite=static_cast<Widget*>(pSender);
  
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
            Team2* team=Team2::create();
            team->show(this);
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
    //Director::getInstance()->getTextureCache()->removeAllTextures();
}
