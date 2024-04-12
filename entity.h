#pragma once
//#include <string>
#include "entityData.h"

#include "image.h"
class entity
{
public:
	entity(int ID);
	~entity();
	
	bool dead;
	// when attacked
	void attacked(int damage);
	double hp_getter();

	bool anyskillchoosen();
	int choose_skill();
	int enemy_skill();
	double skill_cast(int i);
	// change attack status to now
	
	void attacksttchange(bool now);
	bool atkstt_getter();
	void hurtsttchange(bool now);
	bool hurtstt_getter();


	//load image into character texture
	void loadEntityTexture();
	void renderEntity(SDL_Rect dst, int act);
	void renderEntity(int act);
	void renderSkill();
	//image* image_getter();
	void set_rect(SDL_Rect& rect);
	bool inside();
private:
	
	entityData stats;
	std::string sprite[2];
	std::string cast[2];
	image stance[2];
	image skill[2];
	
	// to know if character is attacking
	bool attackstatus;
	bool hurtstatus;
};

