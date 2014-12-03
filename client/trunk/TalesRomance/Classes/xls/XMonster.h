//XMonster自动生成类
#ifndef __fancyHeart__XMonster__
#define __fancyHeart__XMonster__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
class XMonster{

private:
	Value v;
public:
	static XMonster* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getName();
	int getHp();
	int getAp();
	int getMp();
	int getPd();
	int getMd();
	int getTeam1();
	int getTeam2();
	int getTeam3();
	int getTeam4();
	int getTeam5();
	int getTeam6();
};
#endif // defined(__dx__Data__)
