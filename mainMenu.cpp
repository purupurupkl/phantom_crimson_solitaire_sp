
#include "mainMenu.h"
#include "textureLoader.h"
mainMenu::mainMenu() {

}
mainMenu::~mainMenu() {

}
void mainMenu::loadMedia() {
	bg = new image(0, 0);
	bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\granblue-fantasy-relink-character-art-uhdpaper.com-hd-5.1773.jpg"));
	
	
	flag = false;
}

void mainMenu::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		flag = true;
	}
	std::cout << "current state is " << gameM::current << std::endl;

}

void mainMenu::update() {

}

void mainMenu::render() {
	SDL_Rect dst = { 0,0, 1200, 600 };
	bg->render(dst);
	SDL_RenderPresent(gameM::renderer);
}

void mainMenu::clean() {
	if (flag == true) {
		gameM::current = gameM::main_combat;
		flag = false;
		SDL_RenderClear(gameM::renderer);
	}
}