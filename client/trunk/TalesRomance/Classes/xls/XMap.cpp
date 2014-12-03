//XMap
#include "XMap.h"
static XMap* instance;

XMap* XMap::record(Value v){ 
	if(instance==NULL) instance=new XMap();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XMap.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XMap::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XMap::getName(){
	return doc[v.asString().c_str()]["name"].GetString();
}
std::string XMap::getDesc(){
	return doc[v.asString().c_str()]["desc"].GetString();
}
std::string XMap::getPos(){
	return doc[v.asString().c_str()]["pos"].GetString();
}
