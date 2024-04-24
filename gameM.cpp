#include "gameM.h"
#include "mainMenu.h"
#include "charSelect.h"
#include "level2.h"
#include "level1.h"
#include "booster.h"
#include "constants.h"
#include "writer.h"
#include "baseState.h"

mainMenu* mainmenu = new mainMenu();
charSelect* charselect = new charSelect();
//mainCombat* maincombat;
level2* leveltwo = new level2();
level1* levelone = new level1();
booster* boost1 = new booster();
baseState* base = levelone;
int gameM::current = gameM::stage1;
bool gameM::quit = false;
bool gameM::flag = true;            //first loadmedia
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
		window = SDL_CreateWindow("tower", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
		writer::get().font = TTF_OpenFont("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\font\\Roboto-Black.ttf", 12);

		
	}
	return status;
}
void gameM::loadMedia() {
	if (gameM::flag == true) {
		base->loadMedia();
		gameM::flag = false;
	}
}
bool gameM::quitgame() {
	return quit;
}
void gameM::eventHandler(SDL_Event& e) {
	if (e.type == SDL_QUIT) {
		quit = true;
	}
		base->eventHandler(e);
}
void gameM::update() {
	base->update();
}
void gameM::render() {
	base->render();
}
	
void gameM::clean() {
	base->clean();
	if (gameM::flag == true) {
		switch(current) {
		case main_menu:
			base = mainmenu;
			break;
		case stage1:
			base = levelone;
			break;
		case stage2:
			base = leveltwo;
			break;
		case after1:
			base = boost1;
		}
	}
}