#include "entity.h"
#include <iostream>
#include "entityImage.h"
#include "textureLoader.h"
#include "writer.h"
entity::entity() {};
entity::entity(int ID) {	
	abi[0] = new skill();
	abi[1] = new skill();
	//if id = 1 create djeeta, 2 is cag 3 is zeta
	switch (ID) {
		case 1:
			stats = characterStats::DjeetaStats;
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Djeeta[i];
			skillImg[i].set_image(textureLoader::loadTexture(skillImage::Zeta[i].c_str()));
			}
			*abi[0] = skillStats::base;
			*abi[1] = skillStats::Zeta_s2;
			break;
		case 2:
			stats = characterStats::CagliostroStats;
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Cagliostro[i];
			skillImg[i].set_image(textureLoader::loadTexture(skillImage::Zeta[i].c_str()));
			}
			*abi[0] = skillStats::base;
			*abi[1] = skillStats::Zeta_s2;
			break;
		case 3:
			stats = characterStats::ZetaStats;
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Zeta[i];
			skillImg[i].set_image(textureLoader::loadTexture(skillImage::Zeta[i].c_str()));
			}
			*abi[0] = skillStats::base;
			*abi[1] = skillStats::Zeta_s2;
			break;
		case -1:
			stats = characterStats::DogStats;
			for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Dog[i];
			skillImg[i].set_image(textureLoader::loadTexture(skillImage::Zeta[i].c_str()));
			}
			*abi[0] = skillStats::base;
			*abi[1] = skillStats::Zeta_s2;
			break;
	}
	std::cout << stats.atk << " " << stats.name << std::endl;
	dead = false;
	SDL_Rect s1 = { 600, 50, 50, 50 };
	SDL_Rect s2 = { 800, 50, 50, 50 };
	skillImg[0].set_imagepos(s1);
	skillImg[1].set_imagepos(s2);
}
entity::~entity() {

}
void entity::attacked(int damage) {
	stats.hp -= damage;
}
double entity::hp_getter() {
	return stats.hp;
}

int fren::availableSkill() {
	for (int i = 0; i < 2; i++) {
		if (skillImg[i].inside()) {
			if (abi[i]->cooldown == 0) return i;
			else return -1;
		}
	}
	return -1;
}
double entity::skill_cast(int i) {
	double mult = 1;
	if (i != -1) mult = abi[i]->multiplier;
	return stats.atk*mult;
}
void entity::update() {
	if (stats.hp <= 0) dead = true;
	for (int i = 0; i < 2; i++) {
		if (abi[i]->choosen == true) {
			abi[i]->cooldown = abi[i]->cd;
			std::cout << "cooldown " << i << " is now " << abi[i]->cooldown << " from " << abi[i]->cd << std::endl;
			abi[i]->choosen = false;
		}
		else if (abi[i]->cooldown > 0) {
			abi[i]->cooldown--;
			std::cout << "after cooldown " << i << " is now " << abi[i]->cooldown << " from " << abi[i]->cd << std::endl;
		}
	}
}

void entity::set_rect(SDL_Rect& rect) {
	stance[0].set_imagepos(rect);
	stance[1].set_imagepos(rect);
}
void entity::loadEntityTexture() {
	//load texture SOURCE (file name) from entityImage
	// should i just drop that ? 
	for (int i = 0; i < 2; i++) {
		stance[i].set_image(textureLoader::loadTexture(sprite[i].c_str()));
	}
}
void entity::renderEntity(SDL_Rect dst, int act) {
	// trying to render sprite in 2 status: idle and taking turn
	enum {
		idle,
		atk
	};
	stance[act].render(dst);
}
void entity::renderEntity(int act) {
	enum {
		idle,
		atk
	};
	stance[act].autorender();
}
void entity::renderSkill(){
	SDL_Rect board = { 200 ,0, 800, 200 };
	SDL_RenderFillRect(gameM::renderer, &board);
	SDL_Rect msg[2] = { {612, 63, 25, 25},{812, 63, 25, 25} };
	for (int i = 0; i < 2; i++) {
		skillImg[i].autorender();
		skillImg[i].set_alpha(100);
		writer::get().loadText(std::to_string(abi[i]->cooldown), { 0xFF,0xFF,0xFF,0xFF }, msg[i]);
	}
	
}
bool entity::inside() {
	//int x, y;
	//SDL_GetMouseState(&x, &y);
	//SDL_Rect mousenow = { x,y,1,1 };
	//bool inside = SDL_HasIntersection(&mousenow, &pos);
	//return inside;
	return (stance[0].inside() || stance[1].inside());
}
int mob::mob_skill() {
	return 1;
}
void fren::statusUpdate() {

}