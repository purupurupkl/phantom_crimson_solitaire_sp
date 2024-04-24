#include "skill.h"
#include "textureLoader.h"
#include "writer.h"
skill::skill() {};
skill::skill(int tp, double mult, int realcd) {
	type = tp;
	multiplier = mult;
	cooldown = 0;
	cd = realcd;
	choosen = false;
}

skill skill::operator=(const skill& other){
	type = other.type;
	multiplier = other.multiplier;
	cooldown = 0;
	cd = other.cd;
	choosen = false;
	return *this;
};
