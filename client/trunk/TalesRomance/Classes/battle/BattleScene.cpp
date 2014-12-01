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
    
    this->bg=Sprite::create("battleBg.png");
    bg->setPosition(Vec2(wsize.width*0.5,wsize.height*0.5));
    this->addChild(bg,-1);
    
    this->heroNode=Node::create();
    this->addChild(heroNode);
    
    this->heroInfo1=this->ui->getChildByName("heroInfo1");
    this->heroInfo2=this->ui->getChildByName("heroInfo2");
    
    this->initInfo(heroInfo1);
    this->initInfo(heroInfo2);
 
    
    for(int i=0;i<3;i++){
        BattleCard* BattleCard=BattleCard::create(i);
        BattleCard->setScale(0.35);
        BattleCard->setVisible(false);
        BattleCard->setPosition(Vec2(0,60));
        this->heroNode->addChild(BattleCard,1);
        this->BattleCards.pushBack(BattleCard);
    }
    return true;
}

void BattleScene::onEnter()
{
    BaseUI::onEnter();
    
    this->startAnimation();
}

void BattleScene::initInfo(Node* node)
{
    Label* heroName=(Label*)node->getChildByName("name");
    heroName->setString(" 很厉害的主角");
    //Sprite* icon=(Sprite*)node->getChildByName("icon");
    //icon->setDisplayFrame(Sprite::createWithSpriteFrameName("")->displayFrame());
    //Sprite* parter=(Sprite*)node->getChildByName("parter");
    //parter->setDisplayFrame(Sprite::createWithSpriteFrameName("")->displayFrame());
    LoadingBar* hpBar=(LoadingBar*)node->getChildByName("hp");
    hpBar->setPercent(50);
}

void BattleScene::startAnimation()
{
    Size infoSize=this->heroInfo1->getContentSize();
    float mid=wsize.width*0.5;
    this->heroInfo1->setPosition(Vec2(mid,this->wsize.height-infoSize.height));
    this->heroInfo2->setPosition(Vec2(mid,this->wsize.height-infoSize.height));
    this->heroInfo1->runAction(EaseIn::create(MoveBy::create(0.25, Vec2(-mid,0)), 2));
    this->heroInfo2->runAction(EaseIn::create(MoveBy::create(0.25, Vec2(mid,0)), 2));
    
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
    
    this->hero->runAction(JumpTo::create(0.6, Vec2(wsize.width/2.-200,140), 150, 1));
    this->npc->runAction(JumpTo::create(0.6, Vec2(wsize.width/2.+200,140), 150, 1));
    
    this->runAction(Sequence::create(DelayTime::create(0.6),CallFunc::create(CC_CALLBACK_0(BattleScene::playRound, this)), NULL));
}

void BattleScene::playRound()
{
    this->playBattleCard();
    
}

void BattleScene::playBattleCard()
{
    for(int i=0;i<3;i++){
        BattleCard* BattleCard=this->BattleCards.at(i);
        BattleCard->reset(i, 3, Value(3));
        BattleCard->move();
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

void BattleScene::showBuff()
{
    
}

void BattleScene::playEffect(std::string name)
{
    Clip* clip=Clip::create(name+".plist", name,12);
    this->addChild(clip,2);
    
    //spBone* bone=this->skeletonNode->findBone("body");
    //clip->setPosition(Vec2(bone->worldX,bone->worldY+bone->data->length*0.8));
    
    clip->play();
}

void BattleScene::touchButtonEvent(cocos2d::Ref *pSender, Widget::TouchEventType type)
{
    if(type!=TouchEventType::ENDED) return;
    this->clear(true);
}

void BattleScene::onExit()
{
    Node::onExit();
    BattleMgr::getInstance()->clear();
    SpriteFrameCache::getInstance()->removeSpriteFrames();
}