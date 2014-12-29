//
//  WSocket.cpp
//  FancyHeart
//
//  Created by 秦亮亮 on 14-4-23.
//
//

#include "WSocket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "cocos2d.h"
WSocket::WSocket()
{
    this->webSocket = new network::WebSocket();
    //192.168.1.69:2888
    std::string host="ws://127.0.0.1:3010";
    if(!this->webSocket->init(*this,host))
    {
        CC_SAFE_DELETE(this->webSocket);
    }
}

void WSocket::send(short msgType, std::string msg)
{
 

  //  /*
     std::string route="connector.entryHandler.test";
     int msgLen=MSG_FLAG_BYTES+MSG_ROUTE_LEN_BYTES+route.size()+msg.size();
     
     char buffer2[msgLen];
     int offset=0;
     buffer2[offset++]=0;
     int id=3;
     
     do{
     int tmp = id % 128;
     int next = floor(id/128);
     
     if(next != 0){
     tmp = tmp + 128;
     }
     buffer2[offset++] = tmp;
     
     id = next;
     } while(id != 0);
     
     //rote
     buffer2[offset++] = route.size() & 0xff;
     sprintf(buffer2+offset, "%s",route.c_str());
     offset += route.size();
     
     //body
     sprintf(buffer2+offset, "%s",msg.c_str());
     
     //*/
    
    //std::string rote="connector.entryHandler.test";
    int size=sizeof(buffer2);
    char buffer[msg.size()+4];
    int index=0;
    buffer[index++]=msgType & 0xff;
    buffer[index++]=(size >> 16) & 0xff;
    buffer[index++]=(size >> 8) & 0xff;
    buffer[index++]=size & 0xff;
    
//    buffer[index++]=0; //request
//    sprintf(buffer+index, "%lu",rote.size());  //route len
//    index+=sizeof(long);
//    sprintf(buffer+index, "%s",rote.c_str());
//    index+=rote.size();
    
    sprintf(buffer+index,"%s",buffer2);
    log("size:%lu",sizeof(buffer));
    this->webSocket->send((const unsigned char*)buffer, sizeof(buffer));
}

void WSocket::send(short msgId,google::protobuf::Message* msg)
{
   
    /*
    SearchRequest sr;
    sr.set_page_number(31);
    sr.set_query("wahaha");
    sr.set_result_per_page(100);
    */
    char buffer[msg->ByteSize()+6+1];
    
    //headflag 3637(short) msglen(short) msgnum(short) msg
    //htonl(3637);
    int flag=htons(3637);
    memset(buffer,flag,2);  //
    memset(buffer+2, msg->ByteSize()+2+2, 2);
    memset(buffer+2, msgId, 2);
    
    
    //    google::protobuf::io::ArrayOutputStream* out;
//    google::protobuf::io::ZeroCopyOutputStream* rawOut=new google::protobuf::io::ArrayOutputStream(buffer+6,msg->ByteSize());
//    google::protobuf::io::CodedOutputStream* codeOut=new google::protobuf::io::CodedOutputStream(rawOut);
//    msg->SerializeToCodedStream(codeOut);
    
//    this->webSocket->send(buffer, sizeof(buffer));
    this->webSocket->send((const unsigned char*)buffer, sizeof(buffer));
    
}

// Delegate methods
void WSocket::onOpen(network::WebSocket* ws)
{
    log("Websocket (%p) opened", ws);
}

void WSocket::onMessage(network::WebSocket* ws, const network::WebSocket::Data& data)
{
    int msgType=data.bytes[0];
    log("msgType:%d",msgType);
    //int size=memset(<#void *#>, <#int#>, <#size_t#>)
/*
    {
        _sendBinaryTimes++;
        char times[100] = {0};
        sprintf(times, "%d", _sendBinaryTimes);
        
        std::string binaryStr = "response bin msg: ";
        
        for (int i = 0; i < data.len; ++i) {
            if (data.bytes[i] != '\0')
            {
                binaryStr += data.bytes[i];
            }
            else
            {
                binaryStr += "\'\\0\'";
            }
        }
        
//        binaryStr += std::string(", ")+times;ß
//        log("%s", binaryStr.c_str());
//        _sendBinaryStatus->setString(binaryStr.c_str());
    }
 
 */
    log("get data from server!");
}

void WSocket::onClose(network::WebSocket* ws)
{
    log("websocket instance (%p) closed.", ws);
    ws=NULL;
    // Delete websocket instance.
    CC_SAFE_DELETE(ws);
}

void WSocket::onError(network::WebSocket* ws, const network::WebSocket::ErrorCode& error)
{
    log("Error was fired, error code: %d", error);
}

WSocket::~WSocket()
{
    if(this->webSocket)
    {
        this->webSocket->close();
    }
}
