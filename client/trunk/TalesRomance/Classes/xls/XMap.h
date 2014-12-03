//XMap自动生成类
#ifndef __fancyHeart__XMap__
#define __fancyHeart__XMap__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
class XMap{

private:
	Value v;
public:
	static XMap* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getName();
	std::string getDesc();
	std::string getPos();
};
#endif // defined(__dx__Data__)
