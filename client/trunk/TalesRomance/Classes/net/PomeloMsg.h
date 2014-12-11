//
//  PomeloMsg.h
//  TalesRomance
//
//  Created by qll on 14/12/10.
//
//

#ifndef __TalesRomance__PomeloMsg__
#define __TalesRomance__PomeloMsg__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;

#define PKG_HEAD_BYTES  4
#define MSG_FLAG_BYTES  1
#define MSG_ROUTE_CODE_BYTES  2
#define MSG_ID_MAX_BYTES  5
#define MSG_ROUTE_LEN_BYTES  1

#define MSG_ROUTE_CODE_MAX  0xffff

#define MSG_COMPRESS_ROUTE_MASK  0x1
#define MSG_TYPE_MASK  0x7

//#define Package  Protocol.Package  {}
//#define Message  Protocol.Message  {}

#define TYPE_HANDSHAKE  1
#define TYPE_HANDSHAKE_ACK  2
#define TYPE_HEARTBEAT  3
#define TYPE_DATA  4
#define TYPE_KICK  5

#define TYPE_REQUEST  0
#define TYPE_NOTIFY  1
#define TYPE_RESPONSE  2
#define TYPE_PUSH  3

class PomeloMsg : public Ref {
    
    
public:
    static PomeloMsg* create();
    char* msgEncode(int type,const char* body);
    char* packEncode(int type,const char* msg);
};

#endif /* #defined(__TalesRomance__PomeloMsg__) */
