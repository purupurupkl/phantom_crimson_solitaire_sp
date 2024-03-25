#pragma once
#include "gameM.h"
#include "image.h"
#include "textureLoader.h"
#include "entity.h"
class mainCombat
{
public:
	mainCombat();
	~mainCombat();

	void loadMedia();

	//handle mouse events
	void eventHandler(SDL_Event e);

	void update();
	void render();
	void clean();
	static int bgOffset;
private:
	image* bg;
	//3 enemies, 3 allies
	entity* char1;
	entity* char2;
	entity* char3;
	entity* enemy1;
	entity* enemy2;
	entity* enemy3;

};

