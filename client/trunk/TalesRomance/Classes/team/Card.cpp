//
//  Card.cpp
//  TalesRomance
//
//  Created by 秦亮亮 on 14/12/1.
//
//

#include "Card.h"

Card* Card::create(json_t* data)
{
    Card* pRet=new Card();
    if(pRet && pRet->init(data)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool Card::init(json_t* data)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/common.plist");
    
    if(!BaseUI::init("Card.csb", "card.plist")){
        return false;
    }
    this->data=data;;
    this->ui->setPosition(Vec2(0,0));
    this->ui->setAnchorPoint(Vec2(0,0));
    
    this->icon=(Sprite*)this->ui->getChildByName("icon");
    this->rim=(ImageView*)this->ui->getChildByName("rim");
    this->atkIcon=(ImageView*)this->ui->getChildByName("atkIcon");
    this->skillIcon=(ImageView*)this->ui->getChildByName("skillIcon");
    this->level=(Text*)this->ui->getChildByName("level");
    this->useTxt=(Text*)this->ui->getChildByName("useTxt");

    this->selectRim=Clip::create("selected.plist", "kaPaiXuanZe",12);
    
    this->addChild(selectRim);
    this->selectRim->setVisible(false);
    

    for(int i=0;i<STAR_NUM;++i)
    {
        std::string name="icon"+Value(i).asString();
        Sprite* icon=(Sprite*)this->ui->getChildByName(name);
        this->stars.pushBack(icon);
    }

    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool {
        Size size=this->rim->getContentSize();
        Vec2 vec=this->rim->getPosition();
        vec=this->convertToWorldSpace(vec);
        Rect rect=Rect(vec.x-size.width*0.5,vec.y-size.height*0.5,size.width,size.height);
        return rect.containsPoint(touch->getLocation());
    };
    listener->onTouchEnded = CC_CALLBACK_2(Card::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    
    this->resetUI();
    return true;
}

void Card::resetUI()
{
    int xid=json_integer_value(json_object_get(this->data, "xid"));
    this->isUse=json_is_true(json_object_get(this->data, "isUse"));

    XCard* xcard=XCard::record(Value(xid));
    
    this->rim->loadTexture("kapai_"+Value(xcard->getCardType()).asString()+".png",TextureResType::PLIST);

    this->atkIcon->loadTexture("atkType"+Value(xcard->getAtkType()).asString()+".png",TextureResType::PLIST);

    //XSkill* xskill=XSkill::record(Value(xcard->getSkillID()));
    //this->skillIcon->loadTexture("skillicon"+Value(xskill->getIcon()).asString()+".png",TextureResType::PLIST);
    

    this->setUse(isUse);

}

void Card::setUse(bool isUse)
{
    this->isUse=isUse;
    if(isUse){
        this->useTxt->setVisible(true);
        this->icon->setColor( Color3B(110,110,110));
    }else{
        this->useTxt->setVisible(false);
        this->icon->setColor(Color3B(255,255,255));
    }
}

void Card::setSelect(bool isSelect)
{
    if(isSelect){
        this->selectRim->setVisible(true);
        this->selectRim->play(true);
    }else{
        this->selectRim->stopAllActions();
        this->selectRim->setVisible(false);
    }
}

Size Card::getSize()
{
    return this->rim->getContentSize();
}

void Card::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    Vec2 sp=touch->getStartLocation();
    Vec2 ep=touch->getLocation();
    
    if(abs(sp.x-ep.x)<10 && abs(sp.y-ep.y)<10 ){
        this->click(this);
    }
}