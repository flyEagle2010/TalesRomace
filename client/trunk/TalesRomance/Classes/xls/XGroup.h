//XGroup自动生成类
#ifndef __fancyHeart__XGroup__
#define __fancyHeart__XGroup__
#include <iostream>
#include "external/json/document.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
class XGroup{

private:
	Value v;
public:
	static XGroup* record(Value v);
	rapidjson::Document doc;
	/*Administrator:
头两位是伙伴ID 第三位表示这个是这个伙伴的第几个奥义

*/
	int getId();
	/*cth-computer:
此处填入触发奥义时对当前回合的team的手牌颜色的组合的要求*/
	int getGroup();
	/*cth-computer:
此处索引skill表的id*/
	int getSkillId();
};
#endif // defined(__dx__Data__)
