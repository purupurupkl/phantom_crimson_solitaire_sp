#pragma once
#include "commonfunc.h"
extern SDL_Renderer* renderer;
extern SDL_Window* window;
class gameState
{
public:
	bool running;
	//abstract class enforced by pure virtual functions

	virtual void input(SDL_Event &e);
	virtual void exit();
	virtual void enter();
	void shutdown();
	//each state has its own bgtexture 
	SDL_Texture* bgTexture;

	
	static gameState* current;
	static gameState* menuz;
	static gameState* selector;

	gameState();
	virtual ~gameState();
};


