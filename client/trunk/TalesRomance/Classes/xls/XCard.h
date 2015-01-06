//XCard自动生成类
#ifndef __fancyHeart__XCard__
#define __fancyHeart__XCard__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
class XCard{

private:
	Value v;
public:
	static XCard* record(Value v);
	rapidjson::Document doc;
	/*cth-computer:
id总长为4个数字
前两位为伙伴id
后两位为与该伙伴关联的卡牌的id

比如有关羽和张飞俩角色，关羽的id为10 张飞为id为11

于是与关羽相关的牌的id为10xx
与张飞相关的牌的id为11xx*/
	int getId();
	std::string getName();
	/*cth-computer:
黑1
白2
红3
绿4
蓝5*/
	int getCardType();
	/*cth-computer:
物理伤害：1
法术伤害：2
治疗：3*/
	int getAtkType();
	int getAtk();
	int getSkillID();
};
#endif // defined(__dx__Data__)
