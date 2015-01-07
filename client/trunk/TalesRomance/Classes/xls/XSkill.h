//XSkill自动生成类
#ifndef __fancyHeart__XSkill__
#define __fancyHeart__XSkill__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
class XSkill{

private:
	Value v;
public:
	static XSkill* record(Value v);
	rapidjson::Document doc;
	/*cth-computer:
id的结构：
【技能类型】+【id】+【等级】

【技能类型】1位
【id】3位
【等级】2位*/
	int getId();
	std::string getName();
	/*cth-computer:
1技能
2buff*/
	int getType();
	/*cth-computer:
1:物理伤害
2:法术伤害
3:驱散
4:持续治疗
5:不能行动
6:不能放天赋效果
7:物攻增益
8:魔攻增益
9:物防增益
10:魔防增益
11:物攻减益
12:魔攻减益
13:物防减益
14:魔防减益
15:物理减伤
16:魔法减伤
17:不能放奥义
18:物理持续伤害
19:吸血buff
20:物理反伤
21:法术反伤
22:提升卡牌攻击值
23:法术持续伤害*/
	int getAtkType();
	std::string getDesc();
	std::string getIcon();
};
#endif // defined(__dx__Data__)
