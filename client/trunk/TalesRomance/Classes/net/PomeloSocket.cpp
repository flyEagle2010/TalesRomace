//
//  PomeloSocket.cpp
//  TalesRomance
//
//  Created by qll on 14/12/11.
//
//

#include "PomeloSocket.h"
static std::vector<json_t*> messageQueue;

PomeloSocket::PomeloSocket()
{
}

int PomeloSocket::connect(const char* addr, int port)
{
    Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);

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
   
    pc_add_listener(client, PC_EVENT_DISCONNECT, onDisconnectCallback);
    
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
    void (*connect_cb)(pc_request_t *req, int status, json_t *resp )= &PomeloSocket::requstCallback;
    
    json_error_t err;
    json_t* json = json_loads(msg.c_str(), JSON_COMPACT, &err);
    
    int ret=pc_request(client, request, route, json, connect_cb);
    return ret;
}

int PomeloSocket::notify(const char *route, std::string msg)
{
    if(state != CONNECTED_OK){
        return -1;
    }
    pc_notify_t *notify = pc_notify_new();
    
    json_error_t err;
    json_t* json = json_loads(msg.c_str(), JSON_COMPACT, &err);
    int ret = pc_notify(client, notify, route, json, notifyCallback);

    return ret;
}

void PomeloSocket::update(float dt)
{
    while (messageQueue.size()>0) {
        json_t* msg=messageQueue.front();
        messageQueue.erase(messageQueue.begin());
        cocos2d::EventCustom evt(NET_MESSAGE);
        evt.setUserData(msg);
        
        Director::getInstance()->getEventDispatcher()->dispatchEvent(&evt);
        json_decref(msg);
    }
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
    CCLOG("%s", event);
    return;
}

void PomeloSocket::onPushDataCallback(pc_client_t *client, const char *event, void *data)
{
    json_t* json = (json_t* )data;
    const char* msg = json_dumps(json, 0);
    log("receve data:%s,%s", event, msg);
    messageQueue.push_back(json);
    return;
}

void PomeloSocket::requstCallback(pc_request_t *req, int status, json_t *resp)
{
    int error = 0;
    if(status == -1) {
        CCLOG("Fail to send request to server.\n");
    } else if(status == 0) {
        char *json_str = json_dumps(resp, 0);
        CCLOG("server response: %s \n", json_str);
        messageQueue.push_back(resp);
    }
    
    // release relative resource with pc_request_t
    json_t *msg = req->msg;
    pc_client_t *client = req->client;
    json_decref(msg);
    pc_request_destroy(req);
}

void PomeloSocket::notifyCallback(pc_notify_t *ntf, int status)
{
    if(status == -1){
        log("Fail to send notify to server.");
    }
    else if(status ==0){
        log("success to send notify to server:route:%s.",ntf->route);
    }
}

void PomeloSocket::clearRequest()
{

}

void PomeloSocket::clearNotify()
{
}
