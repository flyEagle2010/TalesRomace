//XSheet1自动生成类
#ifndef __fancyHeart__XSheet1__
#define __fancyHeart__XSheet1__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
class XSheet1{

private:
	Value v;
public:
	static XSheet1* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getName();
	std::string getDesc();
	std::string getPos();
};
#endif // defined(__dx__Data__)
