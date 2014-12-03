//XMonster
#include "XMonster.h"
static XMonster* instance;

XMonster* XMonster::record(Value v){ 
	if(instance==NULL) instance=new XMonster();
	if(instance->doc.IsNull()){
		std::string fullPath=FileUtils::getInstance()->fullPathForFilename("XMonster.json");
		std::string str=FileUtils::getInstance()->getStringFromFile(fullPath);
		instance->doc.Parse<0>(str.c_str());
		if(instance->doc.HasParseError()){
			log("GetParseError %s",instance->doc.GetParseError());
		}
	}
	instance->v=v;
	return instance;
}
int XMonster::getId(){
	return doc[v.asString().c_str()]["id"].GetInt();
}
std::string XMonster::getName(){
	return doc[v.asString().c_str()]["name"].GetString();
}
int XMonster::getHp(){
	return doc[v.asString().c_str()]["hp"].GetInt();
}
int XMonster::getAp(){
	return doc[v.asString().c_str()]["ap"].GetInt();
}
int XMonster::getMp(){
	return doc[v.asString().c_str()]["mp"].GetInt();
}
int XMonster::getPd(){
	return doc[v.asString().c_str()]["pd"].GetInt();
}
int XMonster::getMd(){
	return doc[v.asString().c_str()]["md"].GetInt();
}
int XMonster::getTeam1(){
	return doc[v.asString().c_str()]["team1"].GetInt();
}
int XMonster::getTeam2(){
	return doc[v.asString().c_str()]["team2"].GetInt();
}
int XMonster::getTeam3(){
	return doc[v.asString().c_str()]["team3"].GetInt();
}
int XMonster::getTeam4(){
	return doc[v.asString().c_str()]["team4"].GetInt();
}
int XMonster::getTeam5(){
	return doc[v.asString().c_str()]["team5"].GetInt();
}
int XMonster::getTeam6(){
	return doc[v.asString().c_str()]["team6"].GetInt();
}
