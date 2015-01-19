//XError自动生成类
#ifndef __fancyHeart__XError__
#define __fancyHeart__XError__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
class XError{

private:
	Value v;
public:
	static XError* record(Value v);
	rapidjson::Document doc;
	int getId();
	std::string getMsg();
};
#endif // defined(__dx__Data__)
