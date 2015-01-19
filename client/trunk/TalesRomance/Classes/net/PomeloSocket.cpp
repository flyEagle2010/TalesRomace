//
//  PomeloSocket.cpp
//  TalesRomance
//
//  Created by qll on 14/12/11.
//
//

#include "PomeloSocket.h"
static std::vector<json_t*> messageQueue;
static pthread_mutex_t     mMutex;
static PomeloSocket* pomeloSocket=nullptr;

PomeloSocket* PomeloSocket::getInstance()
{
    if(pomeloSocket == nullptr){
        pomeloSocket=new PomeloSocket();
        pthread_mutex_init(&mMutex, NULL);
    }
    return pomeloSocket;
}

int PomeloSocket::connect(const char* addr, int port)
{
    this->client = pc_client_new();
    
    struct sockaddr_in address;
    memset(&address, 0, sizeof(struct sockaddr_in));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(addr);
    
    
    int ret = pc_client_connect(client, &address);
    if(ret) {
        CCLOG("pc_client_connect error:%d",errno);
        pc_client_destroy(client);
        return 0;
    }
    this->state=CONNECTED_OK;
    log("socket connected to:ip:%s,port:%d",addr,port);
    
    // add pomelo events listener
    void (*on_disconnect)(pc_client_t *client, const char *event, void *data) = &PomeloSocket::onDisconnectCallback;
    void (*on_pushData)(pc_client_t *client, const char *event, void *data) = &PomeloSocket::onPushDataCallback;
    pc_add_listener(client, PC_EVENT_DISCONNECT, on_disconnect);
    pc_add_listener(client, PC_EVENT_KICK, on_disconnect);
    pc_add_listener(client, "onTest", on_pushData); //onMsg
    
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);

    return ret;
}

int PomeloSocket::sendMsg(const char* route, json_t* json)
{
    if(state != CONNECTED_OK){
        log("socket has disconnected......");
        return -1;
    }
    Loading::getInstance()->show();
    
    pc_request_t *request = pc_request_new();
    void (*request_cb)(pc_request_t *req, int status, json_t *resp )= &PomeloSocket::requstCallback;

    int ret=pc_request(client, request, route, json, request_cb);
    log("发送数据:route:%s,msg:%s",route,json_dumps(json,0));
    return ret;
}

void PomeloSocket::update(float dt)
{
    pthread_mutex_lock(&mMutex);

    while (messageQueue.size()>0) {
        json_t* msg=messageQueue.at(0);
        messageQueue.erase(messageQueue.begin());
        if(json_integer_value(json_object_get(msg, "code")) != 200){
            int err=json_integer_value(json_object_get(msg, "err"));
            XError* xerror=XError::record(Value(err));
            Manager::getInstance()->showMsg(xerror->getMsg());
        }else{
            cocos2d::EventCustom evt(NET_MESSAGE);
            evt.setUserData(msg);
            Director::getInstance()->getEventDispatcher()->dispatchEvent(&evt);
        }
        //json_decref(msg);
    }
    pthread_mutex_unlock(&mMutex);

}

void PomeloSocket::stop()
{
    // main thread has nothing to do and wait until child thread return.
    //pc_client_join(client);
    // release the client
    pc_client_destroy(client);
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
}

void PomeloSocket::onDisconnectCallback(pc_client_t *client, const char *event, void *data)
{
    CCLOG("＝＝%s", event);
    return;
}

void PomeloSocket::onPushDataCallback(pc_client_t *client, const char *event, void *data)
{
    json_t* json = (json_t* )data;
    json_object_set(json,"route",json_string("onTest"));

    json_incref(json);
    const char* msg = json_dumps(json, 0);
    log("receve data:%s,%s", event, msg);
    pthread_mutex_lock(&mMutex);
    messageQueue.push_back(json);
    pthread_mutex_unlock(&mMutex);

    return;
}

void PomeloSocket::requstCallback(pc_request_t *req, int status, json_t *resp)
{
    //int error = 0;
    if(status == -1) {
        CCLOG("Fail to send request to server.\n");
    } else if(status == 0) {
        json_incref(resp);
        json_object_set(resp,"route",json_string(req->route));
        
        char *json_str = json_dumps(resp, 0);
        log("server response: %s", json_str);
        
        pthread_mutex_lock(&mMutex);

        messageQueue.push_back(resp);
       
        pthread_mutex_unlock(&mMutex);
    }
    Loading::getInstance()->hide();
}

void PomeloSocket::clearRequest()
{

}

