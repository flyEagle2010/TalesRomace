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

//#define LOGIN_URL "http://192.168.1.114:6150/login"
//#define REG_URL "http://192.168.1.114:6150/register"
//#define NET_GATE_IP "192.168.1.114"

#define NET_GATE_PORT 6250         //外网测试端口

#define S_HEATBEAT 1

//======================rote=====================================
#define ROTE_GATE_ENTRY                 "gate.gateHandler.entry"
#define ROTE_CONNECT_ENTRY              "connector.entryHandler.entry"
#define ROTE_CONNECT_CREATE_PLAYER      "connector.roleHandler.createPlayer"
#define ROTE_ROOM_ENTRY                 "room.playerHandler.entry"
#define ROTE_ROOM_PLAYER_DATA           "room.playerHandler.playerData"

#define ROTE_ROOM_TEAM_LIST             "room.playerHandler.teamList"
#define ROTE_ROOM_TEAM_UNLOCK           "room.playerHandler.teamUnlock"
#define ROTE_ROOM_TEAM_CARD             "room.playerHandler.teamCard"
#define ROTE_ROOM_TEAM_CHANGE_CARD      "room.playerHandler.teamChangeCard"

#define ROTE_ROOM_MAP_LIST              "room.playerHandler.mapList"
#define ROTE_ROOM_NODE_LIST             "room.playerHandler.nodeList"
#define ROTE_ROOM_MAZE_LIST             "room.playerHandler.mazeList"
#define ROTE_ROOM_PARTER_LIST           "room.playerHandler.parterList"
#define ROTE_ROOM_PARTER_SELECT         "room.playerHandler.parterSelect"
#define ROTE_ROOM_MAZE_LIST             "room.playerHandler.mazeList"
#define ROTE_ROOM_CLEAR_REWARD          "room.playerHandler.clearReward"

//=======================msgID====================================
#define C_GATE_ENTRY  2001            //给客户端分配connector服务器
#define C_CONNECT_ENTRY 3001          //连接connector服务器 并验证客户端数据
#define C_CREATE_ROLE 3002            //角色创建
#define C_ROOM_ENTRY 4001             //进入游戏
#define S_ROLE_INFO 5001              //角色信息
#define C_TEAM_LIST 6001              //卡组列表
#define C_TEAM_UNLOCK 6002            //卡组解锁
#define C_TEAM_CARD 6003              //卡牌列表
#define C_TEAM_CHANGE_CARD 6004       //卡牌编组
#define C_MAP_LIST 7001               //世界列表
#define C_NODE_LIST 7002              //关卡节点
#define C_PARTER_LIST 7003            //好友列表
#define C_PARTER_SELECT 7004          //选择好友
#define C_MAZE_LIST 7005              //迷宫列表
#define S_CLEAR_REWARD 7006           //通关奖励

#endif