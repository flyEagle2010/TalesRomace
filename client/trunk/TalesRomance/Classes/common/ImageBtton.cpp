//
//  ImageBtton.cpp
//  TalesRomance
//
//  Created by qll on 14/12/4.
//
//

#include "ImageBtton.h"

ImageButton* ImageButton::create(Sprite* sprite)
{
    ImageButton* pRet=new ImageButton();
    if(pRet && pRet->init(sprite)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool ImageButton::init(Sprite* sprite)
{
    this->sprite=sprite;
    this->setTag(sprite->getTag());
    this->addChild(sprite);
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(ImageButton::onTouchBegin, this);
    listener->onTouchEnded = CC_CALLBACK_2(ImageButton::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

bool ImageButton::onTouchBegin(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
    Size size=this->sprite->getContentSize();
    Vec2 pos=this->sprite->convertToWorldSpace(Vec2(0,0));
    Rect rect=Rect(pos.x,pos.y,size.width,size.height);
    if(rect.containsPoint(touch->getLocation()))
    {
        this->sprite->stopAllActions();
        this->sprite->runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.15, 1),NULL) );
        return true;
    }
    return false;
}

void ImageButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent)
{
    if(this->touchEnd){
        this->touchEnd(this);
    }
    
}