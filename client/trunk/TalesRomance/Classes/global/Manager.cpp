//
//  Manager.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-4.
//
//

#include "Manager.h"
#include "Loading.h"
static Manager* instance=nullptr;

Manager* Manager::getInstance(){
    if(instance==nullptr){
        instance=new Manager();
    }
    return instance;
}

void Manager::switchScence(Scene* scene)
{
    if (this->scene) {
        Director::getInstance()->replaceScene(scene);
    }else{
        Director::getInstance()->runWithScene(scene);
    }
    if(this->scene && this->scene->getChildByTag(-100)){
        this->scene->removeChildByTag(-100);
    }
    if(this->scene && this->scene->getChildByTag(-200)){
        this->scene->removeChildByTag(-200);
    }
    this->scene=scene;
    this->childNum=0;
    this->scene->addChild(BlackBg::getInstance(),0,-200);
    this->scene->addChild(Loading::getInstance(),LOADING_LAY,-100);
}

void Manager::initCommonRes()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/smallIcon.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/card.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/common.plist");
}

void Manager::showDlg(cocos2d::ui::Widget *dlg)
{
    this->scene->addChild(dlg);
    this->childNum++;
}

void Manager::showMsg(const string msg)
{
    if (!this->scene)
    {
        return;
    }
    auto msgLayer=Node::create();
    Size size=CCDirector::getInstance()->getWinSize();
    this->scene->addChild(msgLayer, MSG_LAY);
    
    ui::Scale9Sprite* messagBg = ui::Scale9Sprite::create("loading_bg.png");
    messagBg->setPosition(Vec2(size.width/2, size.height/2));
    messagBg->setCapInsets(Rect(50, 50, messagBg->getContentSize().width-100, messagBg->getContentSize().height-100));
    msgLayer->addChild(messagBg);
    
    Label* label=Label::createWithTTF(msg, "Marker Felt.ttf", 24,Size(355,80),TextHAlignment::CENTER,TextVAlignment::CENTER);
    msgLayer->addChild(label,1);
    label->setPosition(Vec2(size.width/2,size.height/2));
    messagBg->setContentSize(Size(label->getContentSize().width+50, label->getContentSize().height+20));
    messagBg->setOpacity(0);
    Sequence* seqBg=Sequence::create(FadeIn::create(0.2),DelayTime::create(1),CCFadeOut::create(0.2),CallFunc::create(CC_CALLBACK_0(Node::removeFromParent, msgLayer)),NULL);
    messagBg->runAction(seqBg);
    
}

