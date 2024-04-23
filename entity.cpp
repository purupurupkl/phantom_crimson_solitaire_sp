#include "entity.h"
#include <iostream>
#include "entityImage.h"
#include "textureLoader.h"
#include "writer.h"
entity::entity() {};
entity::entity(int ID) {	
	//abi[0] = new skill();
	//abi[1] = new skill();
	stance[0] = new image();
	stance[1] = new image();
	skillImg[0] = new image();
	skillImg[1] = new image();
	auto it = characterStats::characterData.find(ID);
	if (it != characterStats::characterData.end()) {
		stats = it->second;
	}
	switch (ID) {
		case 1:
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Nian[i];
			skillImg[i]->set_image(loader::loadTexture(skillImage::Nian[i]));
			}
			abi[0] = skillStats::base;
			abi[1] = skillStats::Zeta_s2;
			break;
		case 2:
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Saga[i];
			skillImg[i]->set_image(loader::loadTexture(skillImage::Saga[i]));
			}
			abi[0] = skillStats::base;
			abi[1] = skillStats::Zeta_s2;
			break;
		case 3:
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::April[i];
			skillImg[i]->set_image(loader::loadTexture(skillImage::April[i]));
			}
			abi[0] = skillStats::base;
			abi[1] = skillStats::Zeta_s2;
			break;
		case -1:
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Dog[i];
			skillImg[i]->set_image(loader::loadTexture(skillImage::Dog[i]));
			}
			abi[0] = skillStats::base;
			abi[1] = skillStats::Zeta_s2;
			break;
	}
	std::cout << stats.atk << " " << stats.name << std::endl;
	dead = false;
	SDL_Rect msg[2] = { {400, 725, 50, 50},{500, 725, 50, 50} };
	skillImg[0]->set_imagepos(msg[0]);
	skillImg[1]->set_imagepos(msg[1]);
}
entity::~entity() {

}
void entity::attacked(int damage) {
	stats.hp -= damage;
}
double entity::hp_getter() {
	return stats.hp;
}
int entity::available(int i) {
	int ans = -1;
	if (abi[i].cooldown != 0) {
		std::cout << "on cd" << std::endl;
		ans = -1;
	}
	else ans = i;
	return ans;
};

int fren::availableSkill() {
	for (int i = 0; i < 2; i++) {
		if (skillImg[i]->inside()) {
			if (abi[i].cooldown == 0) return i;
			else return -1;
		}
	}
	return -1;
}

int entity::skill_cast(int i) {
	double mult = 1;
	if (i != -1) mult = abi[i].multiplier;
	return stats.atk*mult;
}
void entity::cast(int skill, entity* target) {
	//if(abi[skill].type == "attack"){
	target->stats.hp -= skill_cast(skill)*100 / (100 + target->stats.def);
	if (target->stats.hp <= 0) target->dead = true;
	//}
	abi[skill].choosen = true;
}
void entity::update() {
	for (int i = 0; i < 2; i++) {
		if (abi[i].choosen == true) {
			abi[i].cooldown = abi[i].cd;
			std::cout << "cooldown " << i << " is now " << abi[i].cooldown << " from " << abi[i].cd << std::endl;
			abi[i].choosen = false;
		}
		else if (abi[i].cooldown > 0) {
			abi[i].cooldown--;
			std::cout << "after cooldown " << i << " is now " << abi[i].cooldown << " from " << abi[i].cd << std::endl;
		}
	}
}

void entity::set_rect(SDL_Rect& rect) {
	stance[0]->set_imagepos(rect);
	stance[1]->set_imagepos(rect);
}
void entity::loadEntityTexture() {
	//load texture SOURCE (file name) from entityImage
	// should i just drop that ? 
	for (int i = 0; i < 2; i++) {
		stance[i]->set_image(loader::loadTexture(sprite[i]));
	}
}
void entity::renderEntity(SDL_Rect dst, int act) {
	// trying to render sprite in 2 status: idle and taking turn
	enum {
		idle,
		atk
	};
	stance[act]->render(dst);
}
void entity::renderEntity(int act){
	enum {
		idle,
		atk
	};
	stance[act]->autorender();
}
void entity::aniEntity(int act) {
	enum {
		idle,
		atk
	};
	stance[act]->autoanimate();
}
void entity::renderSkill(){
	
	SDL_Rect msg[2] = {{400, 850, 70, 70},{500, 850, 70, 70} };
	for (int i = 0; i < 2; i++) {
		skillImg[i]->render(msg[i]);
		if (abi[i].cooldown != 0) {
			skillImg[i]->set_alpha(100);
			writer::get().loadText(std::to_string(abi[i].cooldown), { 0xFF,0xFF,0xFF,0xFF }, msg[i], 5);
		}
	}
	std::string health = "HP: " + std::to_string(stats.hp) + "/" + std::to_string(stats.maxhp);
	SDL_Rect msghp = { 80, 800, 70, 30 };
	writer::get().loadText(health, { 0x00,200,0x00,0xFF }, msghp, 20);
	std::string atk = "ATK: " + std::to_string(stats.atk) + "/" + std::to_string(stats.maxatk);
	SDL_Rect msgatk = { 80,840,70, 30 };
	writer::get().loadText(atk, { 200,0x00,0x00,0xFF }, msgatk, 20);
	std::string def = "DEF: " + std::to_string(stats.def) + "/" + std::to_string(stats.maxdef);
	SDL_Rect msgdef = { 200,800,70, 25 };
	writer::get().loadText(def, { 255,0xFF,0x00,0xFF }, msgdef, 20);
	writer::get().loadText(stats.name, { 0xFF,0xFF,0xFF,0xFF }, {80, 870,70,20}, 18);

}
void entity::renderHealth(SDL_Rect dst){
	std::string health = std::to_string(stats.hp) + "/" + std::to_string(stats.maxhp);
	SDL_Rect hpbox = { dst.x, dst.y - 50, 50 , 20 };
	writer::get().loadText(health, { 0xFF,0xFF,0xFF,0xFF }, hpbox, 10);
}
bool entity::inside() {
	return (stance[0]->inside() || stance[1]->inside());
}
int mob::mob_skill() {
	return 1;
}
mob::~mob() {
	for (int i = 0; i < 2; i++) {
		delete stance[i];
		delete skillImg[i];
	}
}
void fren::statusUpdate() {

}
fren::~fren() {
	for (int i = 0; i < 2; i++) {
		delete stance[i];
		delete skillImg[i];
	}
}