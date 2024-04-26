#include "level1.h"
#include "allyLoader.h"
void level1::loadMedia() {
	gameM::currentstage = 1;
	bgm = Mix_LoadMUS("resources/cb1.mp3");
	Mix_PlayMusic(bgm, -1);
	bg = IMG_LoadTexture(gameM::renderer, "resources\\bg1.jpg");
	board = IMG_LoadTexture(gameM::renderer, "resources\\board.png");
	allyLoader::get().realfren(ally);


	dst[0] = {220, 450, 280, 200};
	dst[1] = {200, 510, 150, 150};
	dst[2] = {100, 560, 120, 150};


	dst[3] = {450, 360, 250, 250};
	dst[4] = {400, 410, 250, 250};
	dst[5] = {450, 460, 250, 250};
	for (int i = 0; i < 3; i++) {
		ally[i]->set_rect(dst[i]);
	}
	for (int i = 0; i < 3; i++) {
		enemy[i] = new mob(-1);
		enemy[i]->set_rect(dst[i + 3]);
	}
	targetchoosen = false;
	 skillchoosen = false;
	 turntaken = false;
	 enemychoice = -1;
	 allychoice = -1;
	 skillchoice = -1;
	 frame = 0;
	 alive = 3;

	allyturn = 0;
	enemyturn = 0;
	myturn = true;
	current = ally[allyturn];
}
void level1::handlePlayer(SDL_Event& e) {
		enum {
		attack,
		support
	};
	switch (e.key.keysym.sym) {
	case SDLK_z:
		skillchoice = current->available(0);
		break;
	case SDLK_x:
		skillchoice = current->available(1);
		break;
	}
	if (skillchoice != -1) {
		skillchoosen = true;
		int choice = -1;
		switch (e.key.keysym.sym) {
		case SDLK_1:
			choice = 0; //what about dead enemy
			break;
		case SDLK_2:
			choice = 1;
			break;
		case SDLK_3:
			choice = 2;
			break;
		}
		if (choice != -1) {
			if (current->abi[skillchoice].type == attack && enemy[choice]->dead == false) {
				enemychoice = choice;
				targetchoosen = true;
			}
			else if (current->abi[skillchoice].type == support && ally[choice]->dead == false) { //revive mechanism? nah
				allychoice = choice;
				targetchoosen = true;
			}
		}
	}
}
void level1::eventHandler(SDL_Event e){
	if (frame == 0) {					//while animation is NOT playing
		if (current->dead == false) { //turn requirement not met
			if (myturn) {
				if (e.type == SDL_KEYDOWN) {
					handlePlayer(e);
				}
				if (skillchoosen == true && targetchoosen == true) {
					if (enemychoice != -1) current->cast(skillchoice, enemy[enemychoice]);
					else if (allychoice != -1) current->cast(skillchoice, ally[allychoice]);
				
				std::cout << "ally " << allyturn << " took turn " <<  std::endl;
				printf("next turn : character %i\n", allyturn + 1);
				turntaken = true;
				skillchoosen = false;
				targetchoosen = false;
				}
			}
		}
		else {
			turntaken = true;
			frame = 20;
		}
	}
};
		
void level1::clean() {
	
	if (gameM::flag == true) {
		SDL_DestroyTexture(board);
		SDL_DestroyTexture(bg);
		Mix_FreeMusic(bgm);
		bgm = NULL;
		board = NULL;
		current = NULL;
		bg = NULL;
		if (alive == 0) {
		gameM::current = gameM::again;
		}
		else gameM::current = gameM::after1;
		
		for (int i = 0; i < 3; i++) {
			delete enemy[i];
		}
		
	}	
}