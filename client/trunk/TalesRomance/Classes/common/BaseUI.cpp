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
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(""+resName);
    }
    Size size=Director::getInstance()->getWinSize();
    this->ui=CSLoader::createNode(""+fileName);
    this->ui->setAnchorPoint(Vec2(0.5,0.5));
    this->addChild(ui,0);
    this->ui->setPosition(Vec2(size.width*0.5,size.height*0.5));
    return true;
};

void BaseUI::onDlgClose(rapidjson::Value &data)
{
    
}

void BaseUI::onEnter()
{
    Node::onEnter();
    this->initNetEvent();
    
}

void BaseUI::show(BaseUI* preUI,int effectType)
{
    preUI->addChild(this);
    preUI->setOpacity(200);
    return;
    
    
    if(preUI)
    {
        this->preUI=preUI;
        if(effectType==0){
            Mask* preMask=static_cast<Mask*>(this->preUI->getChildByName("mask"));
            if (preMask) {
                preMask->hide();
            }
            Mask* mask=Mask::create(Director::getInstance()->getWinSize());
            this->addChild(mask, -1);
            mask->setName("mask");
            mask->show();
        }else if (effectType==1){
            Sprite* sprite=Sprite::create("background.png");
            Size content=sprite->getContentSize();
            Size winSize=Director::getInstance()->getWinSize();
            sprite->setScale(2);
            sprite->setAnchorPoint(Vec2(0, 0));
            this->addChild(sprite, -1);
        }
        this->preUI->addChild(this);
        
    }
}

void BaseUI::show(int effectType)
{
    Manager::getInstance()->scene->addChild(this,0);
    //Mask::getInstance()->show();
}

void BaseUI::clear(bool isDel)
{
    if(isDel)
    {
        this->removeFromParent();
    }
    else
    {
        this->setVisible(false);
    }
}

void BaseUI::onExit()
{
    if(this->preUI==nullptr){
        Mask::getInstance()->hide();
    }else{
        Mask* preMask=static_cast<Mask*>(this->preUI->getChildByName("mask"));
        if (preMask) {
            preMask->show();
        }
        this->preUI=nullptr;
    }
    Node::onExit();
}