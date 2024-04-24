#pragma once
#include "gameM.h"
class charSelect
{
public:
	charSelect();
	~charSelect();
	void loadMedia();
	//handle mouse events
	void eventHandler(SDL_Event e);
	void update();
	void render();
	void clean();
};

