
#include "mainMenu.h"
#include "textureLoader.h"
#include "allyLoader.h"
mainMenu::mainMenu() {

}
mainMenu::~mainMenu() {

}
void mainMenu::loadMedia() {
	bg = IMG_LoadTexture(gameM::renderer, "C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\granblue-fantasy-relink-character-art-uhdpaper.com-hd-5.1773.jpg");
}

void mainMenu::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		gameM::flag = true;
	}
	std::cout << "current state is " << gameM::current << std::endl;

}

void mainMenu::update() {
	//if (flag == true) {
	//	gameM::current = gameM::stage2;
	//	flag = false;
	//	SDL_RenderClear(gameM::renderer);
	//}
}

void mainMenu::render() {
	SDL_RenderClear(gameM::renderer);
	SDL_Rect dst = { 0,0, 1200, 600 };
	SDL_RenderCopy(gameM::renderer, bg, NULL, NULL);
	SDL_RenderPresent(gameM::renderer);
}

void mainMenu::clean() {
	if (gameM::flag == true) {
		gameM::current = gameM::stage1;
		SDL_DestroyTexture(bg);
		bg = NULL;
	}
}