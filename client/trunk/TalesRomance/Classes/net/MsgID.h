//
//  MsgID.h
//  fancyHeart
//
//  Created by 秦亮亮 on 14-5-4.
//
//

#ifndef fancyHeart_MsgID_h
#define fancyHeart_MsgID_h


#define NET_MESSAGE "netMessage"


//外网测试
#define LOGIN_URL "http://123.57.6.164:6150/login"
#define REG_URL "http://123.57.6.164:6150/register"

#define NET_GATE_IP "123.57.6.164"  //外网测试IP
#define NET_GATE_PORT 6250         //外网测试端口

#define S_HEATBEAT 1


#define GATE_GATEHANDLER_ENTRY 100
#define CONNECTOR_ENTRYHANDLER_ENTRY 101
#define PUSH_DATA 200


#define C_STARTFIGHT 9//开始战斗
#define C_FIGHTRESULT 10//开始战斗
#define C_COMMONMSG 11//通用返回消息
#define C_BATTLE 22 //战斗


static std::map<std::string,int> msges={
    {"gate.gateHandler.entry",GATE_GATEHANDLER_ENTRY},
    {"connector.entryHandler.entry",CONNECTOR_ENTRYHANDLER_ENTRY},
    {"onTest",PUSH_DATA}
};

#endif
