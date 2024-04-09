#pragma once
//#include <string>
#include "entityData.h"

#include "image.h"
class entity
{
public:
	entity(int ID);
	~entity();

	// when attacked
	void attacked(int damage);
	double hp_getter();
	double skill_cast(int i);
	// change attack status to now
	void attacksttchange(bool now);
	bool atkstt_getter();
	void hurtsttchange(bool now);
	bool hurtstt_getter();
	void deadsttchange(bool now);
	bool deadstt_getter();
	
	SDL_Rect pos; //position on the screen
	//load image into character texture
	void loadEntityTexture();
	void renderEntity(SDL_Rect dst, int act);
	void renderSkill();
	//image* image_getter();
	void set_rect(SDL_Rect rect);
	bool inside();
private:
	
	entityData stats;
	std::string sprite[2];
	std::string cast[2];
	image stance[2];
	image skill[2];
	bool dead;
	// to know if character is attacking
	bool attackstatus;
	bool hurtstatus;
};

