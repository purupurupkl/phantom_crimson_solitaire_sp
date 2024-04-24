#pragma once
#include <SDL.h>
class baseState
{
public:
	baseState() {};
	~baseState() {};
	virtual void loadMedia();

	//handle mouse events
	virtual void eventHandler(SDL_Event e);
	virtual void update();
	virtual void render();
	virtual void clean();
};

