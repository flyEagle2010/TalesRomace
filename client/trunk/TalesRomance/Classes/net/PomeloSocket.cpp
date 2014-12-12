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

PomeloSocket::PomeloSocket()
{
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);
    pthread_mutex_init(&mMutex, NULL);
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
    
    log("socket connected to:ip:%s,port:%d",addr,port);
    
    // add pomelo events listener
    void (*on_disconnect)(pc_client_t *client, const char *event, void *data) = &PomeloSocket::onDisconnectCallback;
    void (*on_pushData)(pc_client_t *client, const char *event, void *data) = &PomeloSocket::onPushDataCallback;
    pc_add_listener(client, PC_EVENT_DISCONNECT, on_disconnect);
    pc_add_listener(client, "onPushData", on_pushData);
    
    return ret;
}

int PomeloSocket::sendMsg(const char* route, std::string msg)
{
    if(state != CONNECTED_OK){
        return -1;
    }
    pc_request_t *request = pc_request_new();
    void (*request_cb)(pc_request_t *req, int status, json_t *resp )= &PomeloSocket::requstCallback;
    
    json_error_t err;
    json_t* json = json_loads(msg.c_str(), JSON_COMPACT, &err);
    
    int ret=pc_request(client, request, route, json, request_cb);
    return ret;
}

void PomeloSocket::update(float dt)
{
    pthread_mutex_lock(&mMutex);

    while (messageQueue.size()>0) {
        json_t* msg=messageQueue.at(0);
        log("before deal msg:%s",json_dumps(msg, 0));

        messageQueue.erase(messageQueue.begin());
////        cocos2d::EventCustom evt(NET_MESSAGE);
////        evt.setUserData(msg);
////        Director::getInstance()->getEventDispatcher()->dispatchEvent(&evt);
//        log("deal msg:%s",json_dumps(msg, 0));

        json_decref(msg);
    }
    pthread_mutex_unlock(&mMutex);

}

void PomeloSocket::stop()
{
    // main thread has nothing to do and wait until child thread return.
    pc_client_join(client);
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
        pthread_mutex_lock(&mMutex);
        messageQueue.push_back(resp);
        pthread_mutex_unlock(&mMutex);
        char *json_str = json_dumps(resp, 0);
        CCLOG("server response: %s \n", json_str);
       
    }
}

void PomeloSocket::clearRequest()
{

}

