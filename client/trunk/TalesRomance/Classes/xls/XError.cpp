//XError
#include "XError.h"
static XError* instance;

XError* XError::record(Value v){ 
	if(instance==NULL) instance=new XError();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XError.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XError::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XError::getMsg(){
	return doc[v.asString().c_str()]["msg"].GetString();
}
