//
//  Manager.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-4.
//
//

#ifndef __fancyHeart__Manager__
#define __fancyHeart__Manager__

#include <iostream>
#include <stdio.h>
#include "google/protobuf/message.h"
#include "net/Socket.h"
#include "common/DeviceInfo.h"
#include "MsgID.h"
#include "BaseUI.h"
#include "GConfig.h"
#include "WSocket.h"
#include "PomeloSocket.h"
#include "BlackBg.h"
//#include "XExp.h"
//#include "Formation.h"
USING_NS_CC;
using namespace ui;
using namespace google::protobuf;

#define EVENT_RUN "event_run"
#define EVENT_HERO_EVENTER "event_hero_enter"

#define LOADING_LAY 10
#define MSG_LAY 6
#define GUIDE_LAY 5
#define CHAT_LAY 1

class Manager{
    
public:
    Scene* scene;
    //Socket* socket;
    //WSocket* wsocket;
//    PomeloSocket* psocket;
    int childNum;
public:
    static Manager* getInstance();
    void switchScence(Scene* scene);
    void showDlg(Widget* dlg);
    void showMsg(const string msg);//浮出提示
    int getCurrExp(int exp,int lvl);
    void initCommonRes();
private:
    
};

#endif /* defined(__fancyHeart__Manager__) */
