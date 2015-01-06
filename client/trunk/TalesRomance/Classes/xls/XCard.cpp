//XCard
#include "XCard.h"
static XCard* instance;

XCard* XCard::record(Value v){ 
	if(instance==NULL) instance=new XCard();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XCard.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XCard::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XCard::getName(){
	return doc[v.asString().c_str()]["name"].GetString();
}
int XCard::getCardType(){
	return doc[v.asString().c_str()]["cardType"].GetInt();
}
int XCard::getAtkType(){
	return doc[v.asString().c_str()]["atkType"].GetInt();
}
int XCard::getAtk(){
	return doc[v.asString().c_str()]["atk"].GetInt();
}
int XCard::getSkillID(){
	return doc[v.asString().c_str()]["skillID"].GetInt();
}
