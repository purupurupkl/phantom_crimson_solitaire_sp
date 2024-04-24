#pragma once
//#include "gameM.h"
#include "image.h"
#include "textureLoader.h"
#include "entity.h"
#include "baseState.h"
class mainCombat : public baseState
{
public:
	mainCombat();
	~mainCombat();

	//virtual void loadMedia() override;

	////handle mouse events
	//virtual void eventHandler (SDL_Event e);

	//virtual void update();
	//virtual void render();
	//virtual void clean();
	//static int bgOffset;
	
	int enemyatk();
	SDL_Texture* bg;
	//3 enemies, 3 allies
	fren* ally[3];
	mob* enemy[3];
	
	bool skillchoosen;
	bool targetchoosen;
	bool turntaken;
	int skillchoice;
	int enemychoice;
	int allychoice;
	int frame;
};

