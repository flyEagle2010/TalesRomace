//
//  PomeloMsg.cpp
//  TalesRomance
//
//  Created by qll on 14/12/10.
//
//

#include "PomeloMsg.h"
PomeloMsg* PomeloMsg::create()
{
    PomeloMsg* pRet=new PomeloMsg();
    if(pRet){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

/*
/ /
 * Message protocol encode.
 *
 * @param  {Number} id            message id
 * @param  {Number} type          message type
 * @param  {Number} compressRoute whether compress route
 * @param  {Number|String} route  route code or route string
 * @param  {Buffer} msg           message body bytes
 * @return {Buffer}               encode result
 //
Message.encode = function(id, type, compressRoute, route, msg){
    // caculate message max length
    var idBytes = msgHasId(type) ? caculateMsgIdBytes(id) : 0;
    var msgLen = MSG_FLAG_BYTES + idBytes;
    
    if(msgHasRoute(type)) {
        if(compressRoute) {
            if(typeof route !== 'number'){
                throw new Error('error flag for number route!');
            }
            msgLen += MSG_ROUTE_CODE_BYTES;
        } else {
            msgLen += MSG_ROUTE_LEN_BYTES;
            if(route) {
                route = Protocol.strencode(route);
                if(route.length>255) {
                    throw new Error('route maxlength is overflow');
                }
                msgLen += route.length;
            }
        }
    }
    
    if(msg) {
        msgLen += msg.length;
    }
    
    var buffer = new ByteArray(msgLen);
    var offset = 0;
    
    // add flag
    offset = encodeMsgFlag(type, compressRoute, buffer, offset);
    
    // add message id
    if(msgHasId(type)) {
        offset = encodeMsgId(id, buffer, offset);
    }
    
    // add route
    if(msgHasRoute(type)) {
        offset = encodeMsgRoute(compressRoute, route, buffer, offset);
    }
    
    // add body
    if(msg) {
        offset = encodeMsgBody(msg, buffer, offset);
    }
    
    return buffer;
};
*/
char* PomeloMsg::msgEncode(int type, const char *body)
{
    std::string route="connector.entryHandler.test";
    int size=MSG_FLAG_BYTES+MSG_ROUTE_LEN_BYTES+route.size()+sizeof(body);
    
    char buffer[size];
    int index=0;
    buffer[index++]=0;
    int id=3;
    
    do{
        int tmp = id % 128;
        int next = floor(id/128);
        
        if(next != 0){
            tmp = tmp + 128;
        }
        buffer[index++] = tmp;
        
        id = next;
    } while(id != 0);
    
    //rote
    buffer[index++] = route.size() & 0xff;
    sprintf(buffer+index, "%s",route.c_str());
    index += route.size();
    
    //body
    sprintf(buffer+index, "%s",body);
    
    return buffer;
}

char* PomeloMsg::packEncode(int type, const char *msg)
{
    /*
    Package.encode = function(type, body){
        var length = body ? body.length : 0;
        var buffer = new ByteArray(PKG_HEAD_BYTES + length);
        var index = 0;
        buffer[index++] = type & 0xff;
        buffer[index++] = (length >> 16) & 0xff;
        buffer[index++] = (length >> 8) & 0xff;
        buffer[index++] = length & 0xff;
        if(body) {
            copyArray(buffer, index, body, 0, length);
        }
        return buffer;
    };
    */
    
    int length=msg?sizeof(msg):0;
    char* buffer=new char[PKG_HEAD_BYTES+length];
    int index=0;
    buffer[index++] = type & 0xff;
    buffer[index++] = (length >> 16) & 0xff;
    buffer[index++] = (length >> 8) & 0xff;
    buffer[index++] = length & 0xff;
    sprintf(buffer+index, "%s",msg);
    
    return buffer;
}
