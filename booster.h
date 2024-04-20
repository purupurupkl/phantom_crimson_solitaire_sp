#pragma once
#include <SDL.h>
#include "card.h"
#include <string>
class booster
{
public:
	booster();
	~booster();
	void loadMedia(); //load random(?) cards
	void eventHandler(SDL_Event e);
	void render(); //render cards
	void update(); //update character stats
	void clean(); //quit and change state
	card boost[3]; SDL_Rect msgbox[3]; SDL_Rect textbox[3];
	std::string text[3];
};

