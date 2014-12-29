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
    log("init.......");
    if(!BaseUI::init("BattleScene.csb","fight.plist")){
        return false;
    }
    log("init ok ......");
    this->wsize=Director::getInstance()->getWinSize();
    
//    this->bg=Sprite::create("battleBg.png");
//    bg->setPosition(Vec2(wsize.width*0.5,wsize.height*0.5));
//    this->addChild(bg,-1);
    
    this->heroNode=Node::create();
    this->addChild(heroNode);
    
    this->heroInfos.pushBack(ui->getChildByName("heroInfo1"));
    this->heroInfos.pushBack(ui->getChildByName("heroInfo2"));
    
    log("init card.....");
    for(int i=0;i<3;i++){
        BattleCard* card=BattleCard::create(i);
        this->heroNode->addChild(card,1);
        this->BattleCards.pushBack(card);
        card->setPosition(Vec2(0,60));
        card->setVisible(false);
    }
    log("init card end....");
    
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("smallIcon.plist");
    log("init smallIcon");
    return true;
}

void BattleScene::onEnter()
{
	log("start onEnter");
    BaseUI::onEnter();
    log("end onEnter");
    this->startAnimation(nullptr);
    log("end animation");
}

void BattleScene::startAnimation(json_t* data)
{
    this->data=data;

    std::string fullPath=FileUtils::getInstance()->fullPathForFilename("battle.json");
    std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
    log("str:%s",str.c_str());
    json_error_t error;
    this->data=json_load_file(fullPath.c_str(), JSON_INDENT(4), &error);
    json_t* heros=json_object_get(this->data, "heros");
   
    for(int i=0;i<2;i++){
        json_t* json=json_array_get(heros, i);
        Node* node=this->heroInfos.at(i);
        Label* heroName=(Label*)node->getChildByName("name");
        heroName->setString(json_string_value(json_object_get(json, "name")));
        //Sprite* icon=(Sprite*)node->getChildByName("icon");
        //icon->setDisplayFrame(Sprite::createWithSpriteFrameName("")->displayFrame());
        //Sprite* parter=(Sprite*)node->getChildByName("parter");
        //parter->setDisplayFrame(Sprite::createWithSpriteFrameName("")->displayFrame());
        LoadingBar* hpBar=(LoadingBar*)node->getChildByName("hp");
        hpBar->setPercent(50);
        
        //init hero
        const char* icon=json_string_value(json_object_get(json,"icon"));
        log("init hero");
        Hero* hero=Hero::create(std::string(icon)+".json", std::string(icon)+".atlas", i);
        log("init hero end...........");
        this->heros.pushBack(hero);
        this->heroNode->addChild(hero);
        hero->setPosition(Vec2(this->wsize.width*i, 0));
        hero->setVisible(false);
        
        
        Size infoSize=node->getContentSize();
        float mid=wsize.width*0.5;
        node->setPosition(Vec2(mid,this->wsize.height-infoSize.height));
        node->runAction(EaseIn::create(MoveBy::create(0.25, Vec2(mid*(i?1:-1),0)), 2));
        
        hero->runAction(Sequence::create(DelayTime::create(0.6),Show::create(),JumpTo::create(0.6, Vec2(mid+200*(i?1:-1),140), 150, 1), NULL));
    }
                        
    this->runAction(Sequence::create(DelayTime::create(1.2),CallFunc::create(CC_CALLBACK_0(BattleScene::playRound, this)), NULL));

}

void BattleScene::playRound()
{
    json_t* rounds=json_object_get(data, "rounds");
    
    this->round=json_array_get(rounds, roundIndex);
    
    if(json_array_size(rounds) <= roundIndex){
        this->runAction(Sequence::create(DelayTime::create(1),CallFunc::create(CC_CALLBACK_0(BattleScene::showResult, this)), NULL));
        return;
    }
    int index=json_integer_value(json_object_get(this->round, "attacker"));
    this->attacker=heros.at(index);
    this->defender=index?heros.at(0):heros.at(1);
    if(this->attacker->pos==0){
        this->playBattleCard();
    }else{
        this->attack();
    }
    this->roundIndex++;


}

void BattleScene::playBattleCard()
{
    json_t* cards=json_object_get(this->round, "cards");
    for(int i=0;i<json_array_size(cards);i++){
        json_t* data=json_array_get(cards, i);
        
        BattleCard* card=this->BattleCards.at(i);
        card->reset(i, 3, data);
        card->move();
    }
}

void BattleScene::cardDispear()
{
    if(this->isDispear){
        return;
    }
    this->isDispear=true;
    float duration;
    json_t* cards=json_object_get(this->round, "cards");
    for(int i=0;i<json_array_size(cards);i++){
        BattleCard* card=this->BattleCards.at(i);
        duration=card->playDispear();
    }
    this->runAction(Sequence::create(DelayTime::create(duration),CallFunc::create(std::bind(&BattleScene::buildup, this)), NULL));
}

void BattleScene::buildup()
{
    
    this->attacker->buildup();
}

void BattleScene::attack()
{
    json_t* cards=json_object_get(this->round, "cards");
    if(this->cardIndex >= json_array_size(cards)){
        json_t* aoyi=json_object_get(round, "aoyi");
        if(aoyi){
            float duration=0;
            if(this->attacker->pos==0){
                StandDraw* stand=StandDraw::create();
                this->addChild(stand);
                duration=stand->play();
            }
            CallFunc* petAttack=CallFunc::create(std::bind(&BattleScene::petAttack, this));
            this->runAction(Sequence::create(DelayTime::create(duration),petAttack, NULL));
            return;
        }
    }
    this->attacker->data=json_array_get(cards, this->cardIndex);
    this->attacker->attack();
    this->showBuff(this->attacker->pos);
    this->cardIndex++;
}

void BattleScene::petAttack()
{
    Hero* pet=Hero::create("neZha.json", "neZha.atlas", this->attacker->pos);
    this->heroNode->addChild(pet);
    pet->setPosition(Vec2(wsize.width*this->attacker->pos,this->attacker->getPositionY()));
    pet->type=1;
    pet->data=json_object_get(round, "aoyi");
    json_object_set(pet->data, "isAoYi", json_integer(1));
    
    CallFunc* cf=CallFunc::create(std::bind(&Hero::attack, pet));
    JumpTo* jump=JumpTo::create(0.6, Vec2(wsize.width/2.0,wsize.height/4.0), 200, 1);
    Sequence* sq=Sequence::create(jump,cf, NULL);
    pet->runAction(sq);
    this->attacker->data=pet->data;
    CallFunc* heroAttack=CallFunc::create(std::bind(&Hero::attack, this->attacker));
    this->attacker->runAction(Sequence::create(DelayTime::create(0.6),heroAttack, NULL));
    
    this->showBuff(this->attacker->pos);
    this->cardIndex=0;
}

void BattleScene::attacked()
{
    int hp=json_integer_value(json_object_get(attacker->data, "atkHp"));
    this->defender->attacked(hp);
    this->showBuff(this->defender->pos);
}

void BattleScene::showBuff(int pos)
{
    Sprite* icon=(Sprite*)this->heroInfos.at(pos)->getChildByName("parter");
    float startX=icon->getPositionX()+icon->getContentSize().width*0.5-50;
    for(int i=1;i<6;i++){
        Sprite* icon=Sprite::createWithSpriteFrameName("skillIcon"+Value(i).asString()+".png");
        this->heroInfos.at(pos)->addChild(icon);
        icon->setPosition(Vec2(startX+50*i, 100));
    }
}

void BattleScene::showResult()
{
    BattleResult* result=BattleResult::create();
    result->show(this);
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
