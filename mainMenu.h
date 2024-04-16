#pragma once
#include "gameM.h"
#include "image.h"
class mainMenu
{
public:
	mainMenu();
	~mainMenu();

	void loadMedia();

	//handle mouse events
	void eventHandler(SDL_Event e);

	void update();
	void render();
	void clean();

private:
	image* bg;
	bool flag;
	//image* button;
};
