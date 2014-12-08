//
//  AoyiItem.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#include "AoyiItem.h"

AoyiItem* AoyiItem::create()
{
    AoyiItem* pRet=new AoyiItem();
    if(pRet && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool AoyiItem::init()
{
    if(!BaseUI::init("AoyiItem.csb", "")){
        return false;
    }
    this->ui->setPosition(Vec2(0,0));
    this->ui->setAnchorPoint(Vec2(0,0));
    this->bg=(Sprite*)this->ui->getChildByName("bg");
    return true;
}

void AoyiItem::resetUI()
{
    
}

Size AoyiItem::getSize()
{
    return this->bg->getContentSize();
}