#include "entityData.h"
entityData::entityData(std::string name, double hp, double atk) {
	this->name = name;
	this->hp = hp;
	this->atk = atk;
}
entityData entityData::operator=(const entityData& other) {
	name = other.name;
	hp = other.hp;
	atk = other.atk;
	return *this;
}