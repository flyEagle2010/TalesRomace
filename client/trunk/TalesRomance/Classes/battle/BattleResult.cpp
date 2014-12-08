//
//  BattleResult.cpp
//  TalesRomance
//
//  Created by qll on 14/12/8.
//
//

#include "BattleResult.h"
BattleResult* BattleResult::create()
{
    BattleResult* pRet=new BattleResult();
    if(pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BattleResult::init()
{
    if(!BaseUI::init("Result.csb", "result.plist")){
        return false;
    }
    Size size=Director::getInstance()->getWinSize();
    //this->haoganBar=(LoadingBar*)this->ui->getChildByName("haoganBar");
    //this->potrait=(Sprite*)this->ui->getChildByName("potrait");
    //this->nameLabel=(Text*)this->ui->getChildByName("nameLabel");
    this->coinLabel=(Text*)this->ui->getChildByName("coinLabel");
    this->coinLabel->enableOutline(Color4B(0x00, 0xff, 0x00, 255));
    for(int i=1000;i<1003;i++){
        Button* btn=(Button*)this->ui->getChildByTag(i);
        btn->addClickEventListener(CC_CALLBACK_1(BattleResult::onButtonClick, this));
    }
    return true;
}

void BattleResult::onButtonClick(Ref *pSender)
{
    Button* btn=(Button*) pSender;
    switch (btn->getTag()) {
        case 1000: //重玩
        {
            break;
        }
        case 1001: //返回
        {
            this->clear(true);
            break;
        }
        case 1002: //退出
        {
            Manager::getInstance()->switchScence(HomeScene::createScene());
            break;
        }
    }
}
