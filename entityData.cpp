#include "entityData.h"
entityData::entityData(std::string name, int health, int attack,int defense) {
	this->name = name;
	maxhp = health;
	maxatk = attack;
	maxdef = defense;
	
}
entityData entityData::operator=(const entityData& other) {
	name = other.name;
	maxhp = other.maxhp;
	maxatk = other.maxatk;
	maxdef = other.maxdef;
	hp = maxhp;
	atk = maxatk;
	def = maxdef;
	return *this;
}