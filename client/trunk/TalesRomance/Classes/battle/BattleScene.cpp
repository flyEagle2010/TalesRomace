//
//  BattleScene.cpp
//  fancyHeart
//
//  Created by 秦亮亮 on 14/11/13.
//
//

#include "BattleScene.h"
#include "HomeScene.h"

Scene* BattleScene::createScene(){
	auto scene = Scene::create();
    auto layer = BattleScene::create();
    scene->addChild(layer,0,0);
	return scene;
}

BattleScene* BattleScene::create()
{
    BattleScene* pRet=new BattleScene();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool BattleScene::init(){
    
    if(!BaseUI::init("BattleScene.csb","fight.plist")){
        return false;
    }
    this->wsize=Director::getInstance()->getWinSize();
    
    this->bg=Sprite::create("bg_china1.png");
    bg->setPosition(Vec2(wsize.width*0.5,wsize.height*0.5));
    this->addChild(bg,-1);
    
    this->heroNode=Node::create();
    this->addChild(heroNode);
    
    this->heroInfo1=this->ui->getChildByName("heroInfo1");
    this->heroInfo2=this->ui->getChildByName("heroInfo2");
    this->title=this->ui->getChildByName("title");
    this->bottom=this->ui->getChildByName("bottom");
    
    this->title->setVisible(false);
    this->title->setScale(3);
    
    for(int i=0;i<3;i++){
        Card* card=Card::create(i);
        card->setScale(0.3);
        card->setVisible(false);
        card->setPosition(Vec2(100*(i-1),50));
        this->heroNode->addChild(card);
        this->cards.pushBack(card);
    }
    return true;
}

void BattleScene::onEnter()
{
    BaseUI::onEnter();
    
    this->startAnimation();
}

void BattleScene::startAnimation()
{
    Vec2 vec=this->heroInfo1->getPosition();
    this->heroInfo1->runAction(EaseIn::create(MoveTo::create(0.3, vec-Vec2(300,0)), 10));
    this->heroInfo2->runAction(EaseIn::create(MoveTo::create(0.3, vec+Vec2(300,0)), 2));
    this->title->runAction(Sequence::create(DelayTime::create(0.3),Show::create(),ScaleTo::create(0.3, 1), NULL));
    
    this->runAction(Sequence::create(DelayTime::create(0.6),CallFunc::create(CC_CALLBACK_0(BattleScene::initHero, this)), NULL));
}

void BattleScene::initHero()
{
    Size wsize=Director::getInstance()->getWinSize();
    this->hero=Hero::create("neZha.json", "neZha.atlas", 0);
    this->npc=Hero::create("longNv.json", "longNv.atlas", 1);
    this->heroNode->addChild(hero);
    this->heroNode->addChild(npc);
    this->hero->setPosition(Vec2(0,0));
    this->npc->setPosition(Vec2(wsize.width,0));
    
    this->hero->runAction(JumpTo::create(0.6, Vec2(wsize.width/2.-200,wsize.height/3.0), 300, 1));
    this->npc->runAction(JumpTo::create(0.6, Vec2(wsize.width/2.+200,wsize.height/3.0), 300, 1));
    
    this->runAction(Sequence::create(DelayTime::create(0.6),CallFunc::create(CC_CALLBACK_0(BattleScene::playRound, this)), NULL));
}

void BattleScene::playRound()
{
    this->playCard();
    
}

void BattleScene::playCard()
{
    for(int i=0;i<3;i++){
        Card* card=this->cards.at(i);
        Size csize=card->getContentSize();
        MoveTo* move=MoveTo::create(0.2, Vec2(wsize.width/2.f+(i-1)*150,wsize.height/2.f));
        ScaleTo* st=ScaleTo::create(0.2, 0.6);
        SkewTo* skt=SkewTo::create(0.2,0,30);
        Spawn* sp=Spawn::create(move,st,skt, NULL);
        
        CallFunc* cf=CallFunc::create(std::bind(&Card::useSkill, card));
        card->runAction(Sequence::create(Show::create(),DelayTime::create(0.8*i),sp,SkewTo::create(0.3, 0, 0),cf,NULL));
    }
}

void BattleScene::attack()
{
    this->hero->attack(ani_attack);
}

void BattleScene::petAttack()
{
    this->pet=Hero::create("neZha.json", "neZha.atlas", 2);
    this->heroNode->addChild(pet);
    
    CallFunc* cf=CallFunc::create(std::bind(&Hero::run, this->pet));
    JumpTo* jump=JumpTo::create(0.6, Vec2(wsize.width/2.+200,wsize.height/3.0), 200, 1);
    Sequence* sq=Sequence::create(jump,cf, NULL);
    this->pet->runAction(sq);
}

void BattleScene::attacked()
{
    PHit phit;
    this->npc->attacked(phit);
}

void BattleScene::touchButtonEvent(cocos2d::Ref *pSender, Widget::TouchEventType type)
{
    if(type!=TouchEventType::ENDED) return;
}

void BattleScene::onExit()
{
    Node::onExit();
    BattleMgr::getInstance()->clear();
    SpriteFrameCache::getInstance()->removeSpriteFrames();
}