#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "baseState.h"
class gameM
{
public:

	gameM();
	~gameM();
	bool init();
	void loadMedia();

	//process event
	void eventHandler(SDL_Event &e);

	void update();
	void render();
	void clean();
	static bool flag;
	static bool quitgame();
	static SDL_Renderer* renderer;
	static int current;
	static const int main_menu = 0;
	static const int char_select = 1;
	static const int stage1 = 2;
	static const int after1 = 3;
	static const int stage2 = 4;
	
private:
	static bool quit;
	SDL_Window* window;
	
};


