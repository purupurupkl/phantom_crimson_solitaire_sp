#include "entityData.h"
entityData::entityData(std::string name, int health, int attack) {
	this->name = name;
	maxhp = health;
	maxatk = attack;
	
}
entityData entityData::operator=(const entityData& other) {
	name = other.name;
	maxhp = other.maxhp;
	maxatk = other.maxatk;
	hp = maxhp;
	atk = maxatk;
	return *this;
}