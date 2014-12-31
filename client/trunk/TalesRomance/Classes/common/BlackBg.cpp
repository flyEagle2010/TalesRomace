//
//  BlackBg.cpp
//  fancyHeart
//
//  Created by zhai on 14-6-25.
//
//

#include "BlackBg.h"
static BlackBg* instance;
BlackBg* BlackBg::getInstance()
{
    if (instance==nullptr) {
        instance=new BlackBg();
        Size size=Director::getInstance()->getWinSize();
        instance->init(size);
    }
    return instance;
}

bool BlackBg::init(Size size)
{
    if(!Layout::init())
    {
        return false;
    }
    
    this->setSize(size);
    this->setBackGroundColorType(BackGroundColorType::SOLID);
    this->setBackGroundColor(Color3B::BLACK);
    this->setBackGroundColorOpacity(150);
    this->setVisible(false);
    return true;
}

void BlackBg::show()
{
    this->setVisible(true);
}

void BlackBg::hide()
{
    this->setVisible(false);
}

void BlackBg::onExit()
{
    this->setVisible(false);
}