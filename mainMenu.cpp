
#include "mainMenu.h"
#include "textureLoader.h"
#include "allyLoader.h"
#include "writer.h"
mainMenu::mainMenu() {

}
mainMenu::~mainMenu() {

}
void mainMenu::loadMedia() {
	bg = IMG_LoadTexture(gameM::renderer, "resources\\sagaopening.png");
	if(bg == NULL) std::cout << "could not load texture? " << SDL_GetError() << std::endl;
	alpha = 255;
}

void mainMenu::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		gameM::flag = true;
	}
	std::cout << "current state is " << gameM::current << std::endl;

}
void mainMenu::update() {
	alpha = (alpha + 15) % 255;
}
void mainMenu::render() {
	SDL_RenderClear(gameM::renderer);
	SDL_RenderCopy(gameM::renderer,bg, NULL, NULL);
	std::cout << SDL_GetError();
	writer::get().loadTextFlick("Press any key to continue", { 0xFF,0x00,0x00,0xFF }, { 150,700,300,100 }, 20, alpha);
	SDL_RenderPresent(gameM::renderer);
}



void mainMenu::clean() {
	if (gameM::flag == true) {
		gameM::current = gameM::stage1;
		SDL_DestroyTexture(bg);
		bg = NULL;
	}
}