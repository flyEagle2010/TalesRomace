//
//  AoyiItem.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#include "AoyiItem.h"

AoyiItem* AoyiItem::create(int xid)
{
    AoyiItem* pRet=new AoyiItem();
    if(pRet && pRet->init(xid)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool AoyiItem::init(int xid)
{
    if(!BaseUI::init("AoyiItem.csb", "")){
        return false;
    }
    this->xid=xid;
    this->ui->setPosition(Vec2(0,0));
    this->ui->setAnchorPoint(Vec2(0,0));
    this->bg=(Sprite*)this->ui->getChildByName("bg");
    this->nameLabel=dynamic_cast<Text*>(this->ui->getChildByName("nameLabel"));
    this->typeIcon=dynamic_cast<ImageView*>(this->ui->getChildByName("typeIcon"));

    for(int i=0;i<3;i++){
        ImageView* img=dynamic_cast<ImageView*>(this->ui->getChildByName("cardIcon"+Value(i).asString()));
        this->cards.pushBack(img);
    }
    this->resetUI();
    return true;
}

void AoyiItem::resetUI()
{
    XGroup* xgroup=XGroup::record(Value(this->xid));
    XSkill* xskill=XSkill::record(Value(xgroup->getSkillId()));
    this->nameLabel->setString(xskill->getName());
    this->typeIcon->loadTexture("atkType"+Value(xskill->getAtkType()).asString()+".png",TextureResType::PLIST);
    std::vector<int> arr=Utils::getNum(xgroup->getGroup());
    
    for(int i=0;i<arr.size();i++){
        if(arr.at(i)==0)this->cards.at(i)->setVisible(false);
        else this->cards.at(i)->setVisible(true);
        this->cards.at(i)->loadTexture("teamEditCardType_"+Value(arr[i]).asString()+".png",TextureResType::PLIST);
    }
}

Size AoyiItem::getSize()
{
    return this->bg->getContentSize();
}