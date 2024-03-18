#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
class gameM
{
public:

	gameM();
	~gameM();
	bool init();
	void loadMedia();

	//process event
	void eventHandler();

	void update();
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static int current;

private:
	SDL_Window* window;
	static const int main_menu = 0;
	static const int char_select = 1;
};


