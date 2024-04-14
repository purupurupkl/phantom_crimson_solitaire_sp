#pragma once
#include "gameM.h"
#include "image.h"
#include "textureLoader.h"
#include "entity.h"
#include <queue>
class mainCombat
{
public:
	mainCombat();
	~mainCombat();

	void loadMedia();

	//handle mouse events
	void eventHandler(SDL_Event e);

	void update();
	void render();
	void clean();
	static int bgOffset;
private:
	image* bg;
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
};

