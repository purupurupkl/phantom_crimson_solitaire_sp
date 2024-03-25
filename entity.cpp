#include "entity.h"
#include <iostream>
#include "textureLoader.h"
entity::entity(int ID) {
	//if id = 1 create djeeta, 2 is cag 3 is zeta
	switch (ID) {
	case 1:
		stats = characterStats::DjeetaStats;
		sprite = characterImage::Djeeta;
		break;
	case 2:
		stats = characterStats::CagliostroStats;
		sprite = characterImage::Cagliostro;
		break;
	case 3:
		stats = characterStats::ZetaStats;
		sprite = characterImage::Zeta;
		break;
	case -1:
		stats = characterStats::DogStats;
		sprite = characterImage::Dog;
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
int entity::hp_getter() {
	return stats.hp;
}
void entity::deadsttchange(bool now) {
	dead = now;
}
bool entity::deadstt_getter() {
	return dead;
}
image* entity::image_getter() {
	return &idle;
}
void entity::loadEntityTexture() {
	//load texture SOURCE (file name) from entityImage
	// should i just drop that ? 
	idle.set_image(textureLoader::loadTexture(sprite.c_str()));
}
void entity::renderEntity(SDL_Rect dst) {
	// trying to render idle sprite of 3 char
	idle.render(dst);
}
