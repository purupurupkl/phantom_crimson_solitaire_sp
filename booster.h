#pragma once
#include <SDL.h>
#include "card.h"
#include <string>
#include "baseState.h"
class booster : public baseState
{
public:
	booster();
	~booster();
	void loadMedia() override; //load random(?) cards
	void eventHandler(SDL_Event e) override;
	void render() override; //render cards
	void update() override; //update character stats
	void clean() override; //quit and change state
	card boost[3]; SDL_Rect msgbox[3]; SDL_Rect textbox[3];
};

