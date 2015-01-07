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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/common.plist");

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
    this->regPage=this->ui->getChildByName("regPage");
    this->serverPage->setVisible(false);
    this->regPage->setVisible(false);
    
    this->accountTxt=dynamic_cast<TextField*>(this->accountPage->getChildByName("accountTxt"));
    this->passwordTxt=dynamic_cast<TextField*>(this->accountPage->getChildByName("passTxt"));
    this->btn_login=dynamic_cast<Button*>(this->accountPage->getChildByName("btn_login"));
    this->btn_reg=dynamic_cast<Button*>(this->regPage->getChildByName ("btn_reg"));
    this->btn_login->addClickEventListener(CC_CALLBACK_1(LoginScene::onButtonClick, this));
    this->btn_reg->addClickEventListener(CC_CALLBACK_1(LoginScene::onButtonClick, this));
    //return;
    this->initAccount();
    

   
}

//init 游戏服务器 服务器认证
void LoginScene::initAccount()
{
    auto accountStr =UserDefault::getInstance()->getStringForKey("account");
    auto passwordStr =UserDefault::getInstance()->getStringForKey("password");

    this->accountTxt->setString(accountStr);
    this->passwordTxt->setString(passwordStr);
    if(accountStr=="" || passwordStr==""){
        this->regPage->setVisible(true);
        this->accountPage->setVisible(false);
        this->accountTxt=dynamic_cast<TextField*>(this->regPage->getChildByName("accountTxt"));
        this->passwordTxt=dynamic_cast<TextField*>(this->regPage->getChildByName("passTxt"));
    }
    
    //std::string param="name="+accountStr+"&password="+passwordStr;
    //WebHttp::getInstance()->send(LOGIN_URL ,CC_CALLBACK_1(LoginScene::initGameCallback, this),param.c_str());
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
    
    json_error_t error;
    this->json=json_loads(str.c_str(), data->size(), &error);
    int code=json_integer_value(json_object_get(json, "code"));
    const char* op=json_string_value(json_object_get(json, "op"));
    //int err=json_integer_value(json_object_get(json, "err"));


    if(std::string(op)=="register"){
        if(code==200){
            //添加一个字符串数据到指定key
            UserDefault::getInstance()->setStringForKey("account",accountTxt->getString());
            UserDefault::getInstance()->setStringForKey("password",passwordTxt->getString());
            //提交,生成xml文件
            UserDefault::getInstance()->flush();
        }
        this->btn_reg->setTouchEnabled(true);
    }
    if(std::string(op)=="login"){
        this->btn_login->setTouchEnabled(true);
    }
    
    if(code==200){
        Manager::getInstance()->psocket=new PomeloSocket();
        int connectOk=Manager::getInstance()->psocket->connect(NET_GATE_IP, NET_GATE_PORT);
        json_t* token=json_object_get(json, "token");
        json_t* uid=json_object_get(json, "uid");
        log("token:%s",json_string_value(token));
        if(!connectOk){
            json_t* msg=json_object();
            json_object_set(msg, "uid", uid);
            Manager::getInstance()->psocket->sendMsg("gate.gateHandler.entry", msg);
            
            Manager::getInstance()->psocket->token=token;
        }
    }
}

void LoginScene::onButtonClick(Ref *pSender)
{
    auto button=static_cast<Button*>(pSender);
    int tag=button->getTag();
    switch (tag) {
        case 100:   //登陆
        {
            std::string str="name="+this->accountTxt->getString()+"&password="+this->passwordTxt->getString();
            WebHttp::getInstance()->send(LOGIN_URL, CC_CALLBACK_1(LoginScene::initGameCallback, this),str.c_str());
            button->setTouchEnabled(false);
            break;
        }
        case 101:  //注册账号
        {
            std::string str="name="+this->accountTxt->getString()+"&password="+this->passwordTxt->getString();
            WebHttp::getInstance()->send(REG_URL, CC_CALLBACK_1(LoginScene::initGameCallback, this),str.c_str());
            button->setTouchEnabled(false);
            break;
        }
        default:
            break;
    }
   
    /*
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
     */
        
}

void LoginScene::initNetEvent(){
    auto listener = EventListenerCustom::create(NET_MESSAGE, [=](EventCustom* event){
        json_t* msg=(json_t*)event->getUserData();
        const char* route=json_string_value(json_object_get(msg, "route"));
        log("route:%s,%s",route,json_dumps(msg, 0));
        int msgID=msges[route];
        switch (msgID)
        {
            case GATE_GATEHANDLER_ENTRY:
            {
                Manager::getInstance()->psocket->host=json_object_get(msg, "host");
                Manager::getInstance()->psocket->port=json_object_get(msg, "port");
                
                const char* host=json_string_value(json_object_get(msg, "host"));
                int port=json_integer_value(json_object_get(msg, "port"));
                Manager::getInstance()->psocket->stop();
                if(!Manager::getInstance()->psocket->connect(host, port)){
                    json_t* msg=json_object();
                    json_object_set(msg, "token", Manager::getInstance()->psocket->token);
                    Manager::getInstance()->psocket->sendMsg("connector.entryHandler.entry", msg);
                }
                break;
            }
            case CONNECTOR_ENTRYHANDLER_ENTRY:
            {
                int isNew=json_integer_value(json_object_get(msg, "isNew"));
                isNew=2;
                //新的
                if(isNew==1){
                    RoleCreate* create=RoleCreate::create();
                    create->show(this);
                }
                if(isNew==2){
                    Scene* home=HomeScene::createScene();
                    Manager::getInstance()->switchScence(home);
                }
                break;
            }
            default:
                break;
        }
 
        
        
        return;
        //int reqId=json_integer_value(json_object_get(msg, "reqId"));
//        switch (reqId)
//        {
//            case CONNECTED:
//            {
//                Manager::getInstance()->psocket->host=json_object_get(msg, "host");
//                Manager::getInstance()->psocket->port=json_object_get(msg, "port");
//                
//                const char* host=json_string_value(json_object_get(msg, "host"));
//                int port=json_integer_value(json_object_get(msg, "port"));
//                Manager::getInstance()->psocket->stop();
//                if(!Manager::getInstance()->psocket->connect(host, port)){
//                    json_t* msg=json_object();
//                    json_object_set(msg, "token", Manager::getInstance()->psocket->token);
//                    //json_object_set(msg, "reqId", json_integer(31));
//                    Manager::getInstance()->psocket->sendMsg(NET_GATE_ROTE, msg);
//                }
//                break;
//            }
//            case C_LOGIN:
//            {
//                 Manager::getInstance()->switchScence(HomeScene::createScene());
//                break;
//            }
//            default:
//                break;
//        }
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
}
void LoginScene::onExit()
{
    //this->tabBar->release();

    BaseUI::onExit();
}

