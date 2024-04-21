#pragma once
//#include "gameM.h"
#include "image.h"
#include "textureLoader.h"
#include "entity.h"
#include <queue>
class mainCombat
{
public:
	mainCombat();
	~mainCombat();

	virtual void loadMedia();

	//handle mouse events
	virtual void eventHandler (SDL_Event e);

	virtual void update();
	virtual void render();
	virtual void clean();
	//static int bgOffset;
	

	SDL_Texture* bg;
	//3 enemies, 3 allies
	fren* ally[3];
	mob* enemy[3];// 6 characters...
	SDL_Rect dst[6];
	bool skillchoosen;
	bool enemychoosen;
	bool turntaken;
	int currentturn;
	int skillchoice;
	int enemychoice;
	int allychoice;
	int frame;
	//bool flag;
};

