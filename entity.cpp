#include "entity.h"
#include "entityImage.h"
#include <iostream>
#include "textureLoader.h"
entity::entity(int ID) {
	//if id = 1 create djeeta, 2 is cag 3 is zeta
	switch (ID) {
	case 1:
		stats = characterStats::DjeetaStats;
		for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Djeeta[i];
			cast[i] = skillImage::Djeeta[i];
		}
		break;
	case 2:
		stats = characterStats::CagliostroStats;
		for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Cagliostro[i];
			cast[i] = skillImage::Cagliostro[i];
		}
		break;
	case 3:
		stats = characterStats::ZetaStats;
		for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Zeta[i];
			cast[i] = skillImage::Zeta[i];
		}
		break;
	case -1:
		stats = characterStats::DogStats;
		for (int i = 0; i < 2; i++) {
			sprite[i] = characterImage::Dog[i];
			cast[i] = skillImage::Dog[i];
		}
	}
	std::cout << stats.atk << " " << stats.name << std::endl;
	dead = false;
	attackstatus = false;
	hurtstatus = false;
}
entity::~entity() {

}
void entity::attacked(int damage) {
	stats.hp -= damage;
}
void entity::attacksttchange(bool now) {
	attackstatus = now;
}
bool entity::atkstt_getter() {
	return attackstatus;
}
void entity::hurtsttchange(bool now) {
	hurtstatus = now;
}
bool entity::hurtstt_getter()
{
	return hurtstatus;
}
double entity::hp_getter() {
	return stats.hp;
}
bool entity::anyskillchoosen() {
	bool flag = false;
	if (skill[0].inside() || skill[1].inside()) flag = true;
	return flag;
}
int entity::choose_skill() {
	int i = 0;
	if (skill[1].inside()) {
		i = 1;
		std::cout << "skill " << i << " choosen" << std::endl;
	}
	else if (skill[0].inside()) {
		i = 0;
		std::cout << "skill " << i << " choosen" << std::endl;
	}
	return i; //auto attack by default
}
int entity::enemy_skill() {
	return 1;
}
double entity::skill_cast(int i) {
	double mult = 1;
	if (i == 0) mult = stats.s1.multiplier;
	else if (i == 1) mult = stats.s2.multiplier;
	return stats.atk*mult;
}
//void entity::skill_choosen() {
//	if (skill[1].inside()) {
//		/*if(stats.s2.cooldown != 0)*/
//
//	}
//}
//void entity::deadsttchange(bool now) {
//	dead = now;
//}
//bool entity::deadstt_getter() {
//	return dead;
//}
//image* entity::image_getter() {
//	return &idle;
//}


void entity::set_rect(SDL_Rect& rect) {
	stance[0].set_imagepos(rect);
	stance[1].set_imagepos(rect);
}
void entity::loadEntityTexture() {
	//load texture SOURCE (file name) from entityImage
	// should i just drop that ? 
	for (int i = 0; i < 2; i++) {
		stance[i].set_image(textureLoader::loadTexture(sprite[i].c_str()));
		skill[i].set_image(textureLoader::loadTexture(cast[i].c_str()));
	}
}
void entity::renderEntity(SDL_Rect dst, int act) {
	// trying to render sprite in 2 status: idle and taking turn
	enum {
		idle,
		atk
	};
	if (act == idle) stance[idle].render(dst); 
	else if (act == atk) stance[atk].render(dst);
}
void entity::renderEntity(int act) {
	enum {
		idle,
		atk
	};
	if (act == idle) stance[idle].autorender();
	else if (act == atk) stance[atk].autorender();

}
void entity::renderSkill() {
	SDL_Rect s1 = { 400, 50, 50, 50 };
	SDL_Rect s2 = { 600, 50, 50, 50 };
	skill[0].set_imagepos(s1);
	skill[1].set_imagepos(s2);
	skill[0].render(s1);  // can use autorender here
	skill[1].render(s2);
}
bool entity::inside() {
	//int x, y;
	//SDL_GetMouseState(&x, &y);
	//SDL_Rect mousenow = { x,y,1,1 };
	//bool inside = SDL_HasIntersection(&mousenow, &pos);
	//return inside;
	return (stance[0].inside() || stance[1].inside());
}
