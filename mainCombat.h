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

	void update() override;
	void render() override;
	//virtual void clean();
	//static int bgOffset;
	
	int enemyatk();
	SDL_Texture* bg;
	//3 enemies, 3 allies
	SDL_Rect dst[6];
	fren* ally[3];
	mob* enemy[3];
	entity* current;    //pointer pointing to current turn taker
	bool myturn;		//player's turn. false if enemy's turn
    int allyturn;
    int enemyturn;

	bool skillchoosen; //indicate skill has been selected
	bool targetchoosen;  //target for skill selected
	bool turntaken; //both flags = true

	int skillchoice; 
	int enemychoice;
	int allychoice;
  
    SDL_Texture* board;
	int frame; //frame for animation
	int alive;
	bool allenemydead;
	
	Mix_Music* bgm;
};

