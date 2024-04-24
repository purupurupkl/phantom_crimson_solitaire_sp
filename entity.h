#pragma once
//#include <string>
#include "entityData.h"
#include "skill.h"
#include "image.h"
class entity
{
public:
	entity();
	entity(int ID);
	~entity();
	
	bool dead;
	// when attacked
	int available(int i);
	void cast(int skill, entity* target);
	int skill_cast(int i);
	
	void update();

	//load image into character texture
	void renderEntity(SDL_Rect dst, int act);
	void renderEntity(int act);
	void aniEntity(int act);
	void renderSkill();
	void renderHealth(SDL_Rect dst);
	void set_rect(SDL_Rect& rect);
	bool inside();
	entityData stats;
	skill abi[2];
	std::string sprite[2];
	image* stance[2];
	image* skillImg[2];
	int skillchoice;
};

class fren :
    public entity
{
public:
	using entity::entity;
	fren(int ID) : entity::entity(ID) {};
    ~fren();
	void statusUpdate();	};

class mob :
    public entity
{
public:
    mob(int ID) : entity::entity(ID) {};
	~mob();
    int mob_skill();

};