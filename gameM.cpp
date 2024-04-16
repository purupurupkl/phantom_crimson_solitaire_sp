#include "gameM.h"
#include "mainMenu.h"
#include "charSelect.h"
#include "level1.h"
#include "level2.h"
#include "constants.h"
mainMenu* mainmenu;
charSelect* charselect;
//mainCombat* maincombat;
level1* levelone;
SDL_Renderer* gameM::renderer = NULL;
int gameM::current = gameM::main_menu;
bool gameM::quit = false;
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
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		}
	}
	return status;
}
void gameM::loadMedia() {

	mainmenu = new mainMenu();
	charselect = new charSelect();
	//maincombat = new mainCombat();
	levelone = new level1();
	mainmenu->loadMedia();
	charselect->loadMedia();
	//maincombat->loadMedia();
	levelone->loadMedia();
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
	case main_combat:
		/*maincombat*/levelone->eventHandler(e);
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
	case main_combat:
		/*maincombat*/ levelone->update();
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
	case main_combat:
		/*maincombat*/levelone->render();
		break;
	}

}
void gameM::clean() {
	mainmenu->clean();
	charselect->clean();
	/*maincombat*/levelone->clean();

	//delete(mainmenu);
	//delete(charselect);
	//delete(levelone);
}