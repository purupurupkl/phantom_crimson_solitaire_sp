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
	auto it2 = imageBundle::bundle.find(ID);
	if (it2 != imageBundle::bundle.end()) {
		for (int i = 0; i < 2; i++) {
			stance[i]->set_image(loader::loadTexture(it2->second.first[i]));
			skillImg[i]->set_image(loader::loadTexture(it2->second.second[i]));
		}
	}
	auto it3 = skillStats::skillset.find(ID);
	if (it3 != skillStats::skillset.end()) {
		abi[0] = it3->second.first;
		abi[1] = it3->second.second;
	}
	std::cout << stats.atk << " " << stats.name << std::endl;
	dead = false;
	SDL_Rect msg[2] = { {400, 725, 50, 50},{500, 725, 50, 50} };
	skillImg[0]->set_imagepos(msg[0]);
	skillImg[1]->set_imagepos(msg[1]);
}
entity::~entity() {

}
int entity::available(int i) {
	int ans = -1;
	if (abi[i].cooldown != 0) {
		std::cout << "on cd" << std::endl;
		int w = 0;
		int h = 0;
		TTF_SetFontSize(writer::get().font, 20);
		TTF_SizeText(writer::get().font, "not ready!!!", &w, &h);
		writer::get().loadText("not ready!!!", { 0xFF,0xFF,0xFF,0xFF }, { 400 ,750, w, h }, 20);
		SDL_RenderPresent(gameM::renderer);
		SDL_Delay(100);
		ans = -1;
	}
	else ans = i;
	return ans;
};


int entity::skill_cast(int i) {
	double mult = 1;
	if (i != -1) mult = abi[i].multiplier;
	return stats.atk*mult;
}
void entity::cast(int skill, entity* target) {
	if(abi[skill].type == 0){
		target->stats.hp -= skill_cast(skill)*100 / (100 + target->stats.def);
		if (target->stats.hp <= 0) target->dead = true;
	}
	else if (abi[skill].type == 1) {
		target->stats.hp += skill_cast(skill);
		if (target->stats.hp > target->stats.maxhp) target->stats.hp = target->stats.maxhp; //cap health
	}
	Mix_PlayChannel(-1, abi[skill].sfx, 0);
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
	SDL_Rect cd[2] = {{120, 850, 70, 70},{220, 850, 70, 70} };
	for (int i = 0; i < 2; i++) {
		skillImg[i]->render(cd[i]);
		if (abi[i].cooldown != 0) {
			skillImg[i]->set_alpha(100);
			writer::get().loadText(std::to_string(abi[i].cooldown), { 0xFF,0xFF,0xFF,0xFF }, cd[i], 5);
		}
	}
	std::string health = "HP: " + std::to_string(stats.hp) + "/" + std::to_string(stats.maxhp);
	SDL_Rect msghp = { 475, 805, 70, 30 };
	writer::get().loadText(health, { 0x00,200,0x00,0xFF }, msghp, 20);
	std::string atk = "ATK: " + std::to_string(stats.atk) + "/" + std::to_string(stats.maxatk);
	SDL_Rect msgatk = { 475,830,70, 30 };
	writer::get().loadText(atk, { 200,0x00,0x00,0xFF }, msgatk, 20);
	std::string def = "DEF: " + std::to_string(stats.def) + "/" + std::to_string(stats.maxdef);
	SDL_Rect msgdef = { 560,805 ,70, 25 };
	writer::get().loadText(def, { 255,0xFF,0x00,0xFF }, msgdef, 20);
	writer::get().loadText(stats.name, { 0xFF,0xFF,0xFF,0xFF }, {475, 855 ,50,20}, 15);

}
void entity::renderHealth(SDL_Rect dst){
	SDL_Rect hpbox = { dst.x, dst.y - 50, 30 , 20 };
	hpbox.w = 30 * (float)stats.maxhp / 100;
	SDL_SetRenderDrawColor(gameM::renderer, 0xFF, 0x00, 0x00, 0x00);
	SDL_RenderFillRect(gameM::renderer, &hpbox);
	SDL_Rect hpremain = hpbox;
	hpremain.w = hpbox.w* (stats.hp /(float)stats.maxhp);
	SDL_SetRenderDrawColor(gameM::renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(gameM::renderer, &hpremain);
	//std::string health = std::to_string(stats.hp) + "/" + std::to_string(stats.maxhp);
	//
	//writer::get().loadText(health, { 0xFF,0xFF,0xFF,0xFF }, hpbox, 10);
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
