
#include "mainMenu.h"
#include "textureLoader.h"
mainMenu::mainMenu() {

}
mainMenu::~mainMenu() {

}
void mainMenu::loadMedia() {
	bg = new image(0, 0, 1200, 600);
}

void mainMenu::eventHandler(SDL_Event e) {
	if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEMOTION) {

		bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\granblue-fantasy-relink-character-art-uhdpaper.com-hd-5.1773.jpg"));
		bg->render();
		SDL_RenderPresent(gameM::renderer);
	}
}

void mainMenu::update() {

}

void mainMenu::render() {

}

void mainMenu::clean() {

}