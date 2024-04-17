#include "gameM.h"
#include "mainMenu.h"
#include "charSelect.h"
#include "level2.h"
#include "level1.h"
#include "constants.h"
mainMenu* mainmenu = new mainMenu();
charSelect* charselect = new charSelect();
//mainCombat* maincombat;
level2* leveltwo = new level2();
level1* levelone = new level1();
int gameM::current = gameM::stage1;
bool gameM::quit = false;

SDL_Renderer* gameM::renderer = NULL;
gameM::gameM() {

};
gameM::~gameM() {

};
bool gameM::init() {
	bool status = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("can't init sdl, error %s", SDL_GetError());
		status = false;
	}
	else {
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
			status = false;
		}
		window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window cannnot be created, error: %s", SDL_GetError());
			status = false;
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL) {
				printf("Failed to create renderer, error %s", SDL_GetError());
			}
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		}
		if (TTF_Init() == -1) {
			std::cout << "cant init ttf, " << TTF_GetError() << std::endl;
		}
		
	}
	return status;
}
void gameM::loadMedia() {	
	mainmenu->loadMedia();
	charselect->loadMedia();
	//maincombat->loadMedia();
	levelone->loadMedia();
	leveltwo->loadMedia();
}
bool gameM::quitgame() {
	return quit;
}
void gameM::eventHandler(SDL_Event& e) {
	if (e.type == SDL_QUIT) {
		quit = true;
	}
	switch (current) {
	case main_menu:
		mainmenu->eventHandler(e);
		break;
	case char_select:
		charselect->eventHandler(e);
		break;
	case stage1:
		levelone->eventHandler(e);
		break;
	case stage2:
		leveltwo->eventHandler(e);
		break;
	}
}
void gameM::update() {
	switch (current) {
	case main_menu:
		mainmenu->update();
		break;
	case char_select:
		charselect->update();
		break;
	case stage1:
		/*maincombat*/ levelone->update();
		break;
	case stage2:
		/*maincombat*/ leveltwo->update();
		break;
	}
}
void gameM::render() {
	switch (current) {
	case main_menu:
		mainmenu->render();
		break;
	case char_select:
		charselect->render();
		break;
	case stage1:
		/*maincombat*/levelone->render();
		break;
	case stage2:
		/*maincombat*/leveltwo->render();
		break;
}
	}
	
void gameM::clean() {
	mainmenu->clean();
	charselect->clean();
	/*maincombat*/levelone->clean();
	leveltwo->clean();
	//delete(mainmenu);
	//delete(charselect);
	//delete(levelone);
}