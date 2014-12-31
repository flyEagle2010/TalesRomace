//
//  BaseUI.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14-6-12.
//
//

#include "BaseUI.h"
bool BaseUI::init(std::string fileName,std::string resName)
{
    if(resName != ""){
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(resName);
    }
    Size size=Director::getInstance()->getWinSize();
    this->ui=CSLoader::createNode(fileName);
    this->ui->setAnchorPoint(Vec2(0.5,0.5));
    this->addChild(ui,0);
    this->ui->setPosition(Vec2(size.width*0.5,size.height*0.5));

    return true;
}

void BaseUI::onDlgClose(rapidjson::Value &data)
{
    
}

void BaseUI::onEnter()
{
    Node::onEnter();
    this->initNetEvent();
}

void BaseUI::show(BaseUI* preUI)
{
    this->preUI=preUI;
    BlackBg::getInstance()->show();
    this->preUI->getEventDispatcher()->pauseEventListenersForTarget(preUI,true);
    Manager::getInstance()->showDlg(this);
}

void BaseUI::clear(bool isDel)
{
    this->preUI->getEventDispatcher()->resumeEventListenersForTarget(preUI,true);
    if(Manager::getInstance()->childNum == 1){
        BlackBg::getInstance()->hide();
    }
    if(isDel){
        Manager::getInstance()->childNum--;
        this->removeFromParent();
    }else{
        this->setVisible(false);
    }
}

void BaseUI::onExit()
{
    this->preUI=nullptr;
    Node::onExit();
}