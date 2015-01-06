//XGroup
#include "XGroup.h"
static XGroup* instance;

XGroup* XGroup::record(Value v){ 
	if(instance==NULL) instance=new XGroup();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XGroup.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XGroup::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
int XGroup::getGroup(){
	return doc[v.asString().c_str()]["group"].GetInt();
}
int XGroup::getSkillId(){
	return doc[v.asString().c_str()]["skillId"].GetInt();
}
