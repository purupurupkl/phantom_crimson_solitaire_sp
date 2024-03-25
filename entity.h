#pragma once
//#include <string>
#include "entityData.h"
#include "entityImage.h"
#include "image.h"
class entity
{
public:
	entity(int ID);
	~entity();

	// when attacked
	void attacked(int damage);
	int hp_getter();

	// change attack status to now
	void attacksttchange(bool now);
	bool atkstt_getter();
	void hurtsttchange(bool now);
	bool hurtstt_getter();
	void deadsttchange(bool now);
	bool deadstt_getter();

	//load image into character texture
	void loadEntityTexture();
	void renderEntity(SDL_Rect dst);
	image* image_getter();


private:
	entityData stats;
	std::string sprite;
	image idle;
	bool dead;
	// to know if character is attacking
	bool attackstatus;
	bool hurtstatus;
};

