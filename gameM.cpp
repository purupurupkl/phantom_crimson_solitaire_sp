#include "gameM.h"
#include "mainMenu.h"
#include "charSelect.h"
#include "level2.h"
#include "level1.h"
#include "booster.h"
#include "constants.h"
#include "writer.h"
mainMenu* mainmenu = new mainMenu();
charSelect* charselect = new charSelect();
//mainCombat* maincombat;
level2* leveltwo = new level2();
level1* levelone = new level1();
booster* boost1 = new booster();
int gameM::current = gameM::stage1;
bool gameM::quit = false;
bool gameM::flag = true;
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
		writer::get().font = TTF_OpenFont("D:\\vslib\\SDL2_ttf-2.22.0\\Arial.ttf", 12);

		
	}
	return status;
}
void gameM::loadMedia() {
	switch (current) {
		case main_menu:
			if(gameM::flag == true) mainmenu->loadMedia();
			gameM::flag = false;
			break;
		case char_select:
			if (gameM::flag == true) charselect->loadMedia();
			gameM::flag = false;
			break;
		case stage1:
			if (gameM::flag == true) levelone->loadMedia();
			gameM::flag = false;
			break;
		case stage2:
			if (gameM::flag == true) leveltwo->loadMedia();
			gameM::flag = false;
			break;
		case after1:
			if (gameM::flag == true) boost1->loadMedia();
			gameM::flag = false;
			break;
	}
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
	case after1:
		boost1->eventHandler(e);
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
	case after1:
		boost1->update();
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
	case after1:
		boost1->render();
		break;
	case stage2:
		leveltwo->render();
		break;
	}
}
	
void gameM::clean() {
	switch (current) {
	case main_menu:
		mainmenu->clean();
		break;
	case char_select:
		charselect->clean();
		break;
	case stage1:
		/*maincombat*/levelone->clean();
		break;
	case after1:
		boost1->clean();
		break;
	case stage2:
		leveltwo->clean();
		break;
	}
	//delete(mainmenu);
	//delete(charselect);
	//delete(levelone);
}