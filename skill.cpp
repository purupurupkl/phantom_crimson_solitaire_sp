#include "skill.h"
#include "textureLoader.h"
#include "writer.h"
skill::skill() {};
skill::skill(int tp, double mult, int realcd, std::string name) {
	type = tp;
	multiplier = mult;
	cooldown = 0;
	cd = realcd;
	s_path = name;
	sfx = NULL;
	choosen = false;
}

skill skill::operator=(const skill& other){
	type = other.type;
	multiplier = other.multiplier;
	cooldown = 0;
	cd = other.cd;
	s_path = other.s_path;
	sfx = Mix_LoadWAV(s_path.c_str());
	choosen = false;
	return *this;
};
//int skill::use() {
//	return mult
//}
