#include "LoginScene.h"
#include "external/json/document.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ShaderNode.h"

#include "BattleMgr.h"
Scene* LoginScene::createScene()
{
    auto scene = Scene::create();
    auto layer = LoginScene::create();
    scene->addChild(layer);
    return scene;
}

LoginScene* LoginScene::create()
{
    LoginScene* loginScene=new LoginScene();

    if (loginScene && loginScene->init()) {
        loginScene->autorelease();
        return loginScene;
    }
    CC_SAFE_DELETE(loginScene);
    return nullptr;
}

bool LoginScene::init()
{
    if(!BaseUI::init("LoginScene.csb","login.plist"))
    {
        return false;
    }
    return true;
}

void LoginScene::onEnter()
{
    BaseUI::onEnter();
    this->accountPage=this->ui->getChildByName("accountPage");
    this->serverPage=this->ui->getChildByName("serverPage");
    this->serverPage->setVisible(false);
    
    this->accountTxt=dynamic_cast<TextField*>(this->accountPage->getChildByName("accountTxt"));
    this->passwordTxt=dynamic_cast<TextField*>(this->accountPage->getChildByName("passTxt"));
    this->btn_login=dynamic_cast<Button*>(this->accountPage->getChildByName("btn_login"));
    this->btn_login->addClickEventListener(CC_CALLBACK_1(LoginScene::onButtonClick, this));
    
    this->initAccount();
    
    //Manager::getInstance()->wsocket=new WSocket();
    Manager::getInstance()->psocket=new PomeloSocket();
    int connectOk=Manager::getInstance()->psocket->connect("127.0.0.1", 3010);
    if(!connectOk){
        const char* route = "connector.entryHandler.test";
        json_t* msg=json_object();
        json_object_set(msg, "username", json_string("wahaha"));
        json_object_set(msg, "rid", json_integer(21));
        json_object_set(msg, "reqId", json_integer(31));
        
        Manager::getInstance()->psocket->sendMsg(route, msg);
    }
}

//init 游戏服务器 服务器认证
void LoginScene::initAccount()
{
    auto accountStr =UserDefault::getInstance()->getStringForKey("account");
    auto passwordStr =UserDefault::getInstance()->getStringForKey("password");

    this->accountTxt->setString(accountStr);
    this->passwordTxt->setString(passwordStr);
}


void LoginScene::resetUI()
{
    /*
    ui::ScrollView* scrollView=dynamic_cast<ui::ScrollView*>(serverPage->getChildByName("serverList"));
    Button* groupBtn=dynamic_cast<Button*>(scrollView->getChildByName("btn_serverGroup"));
    groupBtn->setTitleText("1-5区");
    int serverNum=this->sData["areaList"].Size();
    std::vector<Button*> buttons={groupBtn};

    for(int i=1;i<serverNum/5;i++){
        Button* btn=dynamic_cast<Button*>(groupBtn->clone());
        btn->setTitleText("");
        scrollView->addChild(btn);
        buttons.push_back(btn);
    }
    this->tabBar=TabBar::create(buttons);
    this->tabBar->retain();
  
    
    int pNum=MIN(serverNum,5);
    int i=0;
    Button* serverBtn=dynamic_cast<Button*>(this->serverPage->getChildByName("btn_server"));
    serverBtn->setTitleText(this->sData["areaList"][i]["name"].GetString());
    serverBtn->setTag(this->sData["areaList"][i]["id"].GetInt());
    
    Vec2 start=serverBtn->getPosition();
    Size size=serverBtn->getContentSize();
    for(i=1;i<pNum;i++){
        rapidjson::Value& v=this->sData["areaList"][i];
        Button* btn=dynamic_cast<Button*>(serverBtn->clone());
        btn->setTitleText(v["name"].GetString());
        btn->setTag(v["id"].GetInt());
        this->serverPage->addChild(btn);
        btn->setPosition(start+Vec2((i%2)*(size.width+10),-(i/2)*(size.height+30)));
        btn->addClickEventListener(CC_CALLBACK_1(LoginScene::onButtonClick, this));
    }
    
     */
}

void LoginScene::initGameCallback(std::vector<char> *data)
{
    std::string str(data->begin(),data->end());
    sData.Parse<0>(str.c_str());
    log("loginData:%s",str.c_str());
    if (sData["loginState"].GetInt()!=0) {//先用以后修改
        log("登录认证失败！");
    }else if(sData["areaList"].Size()<1){
        log("服务列表数据长度不够");
    }else{
        this->resetUI();
    }
    this->btn_login->setTouchEnabled(true);
    this->accountPage->setVisible(false);
    this->serverPage->setVisible(true);
    
    //添加一个字符串数据到指定key
    UserDefault::getInstance()->setStringForKey("account",accountTxt->getString());
    UserDefault::getInstance()->setStringForKey("password",passwordTxt->getString());
    //提交,生成xml文件
    UserDefault::getInstance()->flush();
}

void LoginScene::onButtonClick(Ref *pSender)
{
    auto button=static_cast<Button*>(pSender);
    int tag=button->getTag();
    //登陆
    if(tag==101) {
        Manager::getInstance()->switchScence(HomeScene::createScene());
        //Manager::getInstance()->wsocket->send(4,"{uid:1,name:\"test\",route\"connector.entryHandler.test\"}");
        //Manager::getInstance()->wsocket->send(4, "{uid:1,route:2}");
        
        return;
        std::string str="account="+this->accountTxt->getString()+"&password="+this->passwordTxt->getString();
        WebHttp::getInstance()->send(HTTP_URL, CC_CALLBACK_1(LoginScene::initGameCallback, this),str.c_str());
        button->setTouchEnabled(false);
        return;
    }
    // 选组
    if(tag>300){
        this->tabBar->setIndex(tag-301);
        return;
    }
    //选服
    if(tag <= this->sData["areaList"].Size()){
        Manager::getInstance()->socket=new Socket();
        string ip=this->sData["areaList"][tag-1]["ip"].GetString();
        int port=this->sData["areaList"][tag-1]["port"].GetInt();
        Manager::getInstance()->socket->init(ip, port);
    }
        
}

void LoginScene::initNetEvent(){
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        NetMsg* msg = static_cast<NetMsg*>(event->getUserData());
        switch (msg->msgId)
        {
            case CONNECT_ERROR:
            {
                
#if COCOS2D_DEBUG
                auto scene=HomeScene::createScene();
                Manager::getInstance()->switchScence(scene);
                Manager::getInstance()->showMsg("进入单机模式，本地数据启动");
#endif
                break;
            }
            case CONNECTED:
            {
                Loading::getInstance()->hide();

                LoginReq pbLogin;
                pbLogin.set_account(sData["userBean"]["name"].GetString());
                pbLogin.set_key(sData["key"].GetString());
                pbLogin.set_areaid(sData["areaList"][2]["id"].GetInt());
                Manager::getInstance()->socket->send(C_LOGIN, &pbLogin);
                break;
            }
            case C_LOGIN:
            {
                 Manager::getInstance()->switchScence(HomeScene::createScene());
                break;
            }
            default:
                break;
        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
}
void LoginScene::onExit()
{
    //this->tabBar->release();

    BaseUI::onExit();
}

