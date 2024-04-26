#include "ending.h"
#include "gameM.h"
#include "allyLoader.h"
#include "writer.h"
void ending::loadMedia() {
	std::cout << "loading ending media " << std::endl;
	if (gameM::won == true) bg = IMG_LoadTexture(gameM::renderer, "resources\\winner.png");
	else bg = IMG_LoadTexture(gameM::renderer, "resources\\loser.jpg");
};
void ending::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_x) {
			gameM::flag = true;
		}
		if (e.key.keysym.sym == SDLK_q) {
			gameM::quit = true;
		}
	}
	
}
void ending::update(){

}
void ending::render() {
	SDL_RenderClear(gameM::renderer);
	SDL_RenderFillRect(gameM::renderer, NULL);
	SDL_RenderCopy(gameM::renderer, bg, NULL, NULL);
	if(gameM::won == true) 
		writer::get().loadText("you won this very short and bad game!!!", { 0x00,0x00,0x00,0xFF }, { 70,100,400,60 }, 15);
	else
		writer::get().loadText("you cannot pass this very short and bad game???", { 0x00,0x00,0x00,0xFF }, { 70,100,400,60 }, 15);
	writer::get().loadTextWrapped("press x to play again or press Q to quit", { 0x00,0x00,0x00,0xFF }, { 200,900,200,100 }, 15, 200);
	SDL_RenderPresent(gameM::renderer);
}
void ending::clean() {
	if (gameM::flag == true) {
		gameM::current = gameM::main_menu;
		allyLoader::get().reset();
		SDL_DestroyTexture(bg);
		bg = NULL;
	}
	
};