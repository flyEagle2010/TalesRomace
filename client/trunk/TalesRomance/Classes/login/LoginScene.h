#ifndef __fancyHeart__LoginScene__
#define __fancyHeart__LoginScene__

#include "cocos2d.h"
#include "ui/UIButton.h"
#include "ui/UIText.h"
#include "Manager.h"
#include "WebHttp.h"
#include "HomeScene.h"
#include "Loading.h"
#include "TabBar.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
class LoginScene : public BaseUI
{
public:

    static cocos2d::Scene* createScene();
    static LoginScene* create();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    virtual void resetUI();
private:
    rapidjson::Document sData;
    void initAccount();
    void initGameCallback(std::vector<char> *data);
    void initNetEvent();
    void onButtonClick(Ref *pSender);
    
    Node* accountPage;
    Node* serverPage;
    
    TextField* accountTxt;//账号输入框
    TextField* passwordTxt;//密码输入框
    Button* btn_login;
    TabBar* tabBar;
};

#endif // __HELLOWORLD_SCENE_H__
