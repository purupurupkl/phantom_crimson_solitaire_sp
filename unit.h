#pragma once
#include "BaseObject.h"
extern SDL_Renderer* renderer;
#define UNIT_WIDTH = 64
#define UNIT_HEIGHT = 91

class unit : public BaseObject
{
public:
	unit();
	virtual ~unit();
	bool dead();
	void ActionHandler(SDL_Event event);
	void render(int x, int y, SDL_Rect* currentClip);
protected:
	int name;
	int origin;
	int hp;
	int atk;
	int def;
};

