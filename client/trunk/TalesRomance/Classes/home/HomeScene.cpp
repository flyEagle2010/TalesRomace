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
    Size dSize(1136,640);
    Size size=Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    //float scale=fmin(size.width/dSize.width,size.height/dSize.height);

    
    
    
    this->initUi();
    
	return true;
}

void HomeScene::intAnimation(string plist,string effectName,int fps,int moveSpeed,float scale,Vec2 starP,Vec2 endP)
{
    Clip* clip=Clip::create(plist,effectName,fps);
    comLayout->addChild(clip,1);
    clip->setScale(scale);
    clip->play(true);
    clip->setPosition(starP);
    auto move = MoveBy::create(abs(endP.x-starP.x)/moveSpeed, Vec2(endP.x-starP.x,0));
    auto moveBack=move->reverse();
    auto delay=DelayTime::create(2);
    auto seq = Sequence::create(
                                CallFuncN::create(CC_CALLBACK_0(Clip::setScaleX, clip,scale)),
                                move,
                                delay,
                                CallFuncN::create(CC_CALLBACK_0(Clip::setScaleX, clip,-scale)),
                                moveBack,
                                delay->clone(),NULL);
    clip->runAction(RepeatForever::create(seq));

}

void HomeScene::initUi()
{
    PRole role=Manager::getInstance()->getRoleData()->role();
    auto widget=static_cast<Widget*>(comLayout->getChildByName("home_top"));
    
    Widget* leftPg = static_cast<Widget*>(widget->getChildByName("leftPg"));
    static_cast<Text*>(leftPg->getChildByName("txt_name"))->setString(role.rolename());
    
    static_cast<TextAtlas*>(leftPg->getChildByName("vipLevelLabel"))->setString(Value(role.viplvl()).asString());
    static_cast<TextAtlas*>(leftPg->getChildByName("levelLabel"))->setString(Value(role.level()).asString());
    
    widget=static_cast<Widget*>(widget->getChildByName("centerPg"));
    static_cast<Text*>(widget->getChildByName("txt_currency"))->setString(Value(role.rmb()).asString());
    static_cast<Text*>(widget->getChildByName("txt_diamond"))->setString(Value(role.coin()).asString());
    static_cast<Text*>(widget->getChildByName("txt_stamina"))->setString(Value(role.stamina()).asString());
    
}

void HomeScene::onEnter()
{
    BaseUI::onEnter();
}

void HomeScene::touchButtonEvent(Ref* pSender,TouchEventType type)
{
    auto button=static_cast<Button*>(pSender);
    if (!button) {
        return;
    }
    switch(type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            
            break;
   
        case TouchEventType::TOUCH_EVENT_ENDED:
            switch (button->getTag()) {
                case 10065://聊天按钮
                {
                    break;
                }
                case 10037://下面最右边的按钮
                {
                    break;
                }
                case 10034:
                {
                    break;
                }
                case 10036:
                {
                    break;
                }
                    
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void HomeScene::touchBuildEvent(cocos2d::Ref *pSender, TouchEventType type)
{
    auto sprite=static_cast<Sprite*>(pSender);
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            sprite->stopAllActions();
            sprite->runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.15, 1),NULL) );
            break;
       
        case TouchEventType::TOUCH_EVENT_ENDED:
        {
            switch (sprite->getTag())
            
            {
                case 10001: //竞技场
                {
                    
                    //gate->setPosition(Vec2(0,0));
                    break;

                }
                case 10002: //市场
                {                
                    
                    break;

                }
                case 10003: //战场pve
                {
//                    Gate* gate = Gate::create();
//                    gate->show();
                    //this->addChild(gate);
//                    GateMap* gateMap=GateMap::create(this, "100");
//                    gateMap->show();
                    break;
                }
                case 10004: //英雄编队（卡组）
                {
                    
                    break;
                }
                case 10005: //英雄属性
                {
//                    RoleAllList*roleAllList = RoleAllList::create();
//                    roleAllList->show();
                        break;
                }
                case 10006: //召唤
                {
//                    RoleList* roleList = RoleList::create();
//                    roleList->show();
                    break;
                }
                default:
                    break;
            }
        }
            break;
        default:
            break;
    }
}

void HomeScene::touchIconEvent(Ref *pSender, TouchEventType type)
{
    auto sprite=static_cast<Sprite*>(pSender);
    switch (type)
    {
        case TouchEventType::TOUCH_EVENT_BEGAN:
            sprite->stopAllActions();
            sprite->runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.15, 1),NULL) );
            break;
        case TouchEventType::TOUCH_EVENT_ENDED:
            break;
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
        switch (msg->msgId)
        {
            case C_UPROLE:
            {
                this->initUi();
//                LoginResp pm;
//                pm.ParseFromArray(msg->bytes, msg->len);
            }
                break;
            default:
                break;
        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void HomeScene::onExit()
{
    BaseUI::onExit();
    this->removeAllChildrenWithCleanup(true);
    TextureCache::getInstance()->removeAllTextures();
}