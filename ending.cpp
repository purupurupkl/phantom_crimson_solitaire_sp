#include "ending.h"
#include "gameM.h"
#include "allyLoader.h"
#include "writer.h"
void ending::loadMedia() {
	if (gameM::won == true) bg = IMG_LoadTexture(gameM::renderer, "resources\\winner.png");
	else bg = IMG_LoadTexture(gameM::renderer, "resources\\loser.jpg");
	restart = false;
};
void ending::eventHandler(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		if (e.key.keysym.sym == SDLK_SPACE) {
			restart = true;
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
	if(gameM::won == true) 
		writer::get().loadTextWrapped("you won this very short and bad game!!!", { 0xFF,0xFF,0xFF,0xFF }, { 100,100,200,200 }, 20, 200);
	else
		writer::get().loadTextWrapped("you cannot pass this very short and bad game???", { 0xFF,0xFF,0xFF,0xFF }, { 100,100,200,200 }, 20, 200);
	writer::get().loadTextWrapped("press spacebar to play again or press Q to quit", { 0xFF,0xFF,0xFF,0xFF }, { 200,600,200,200 }, 20, 200);
	SDL_RenderPresent(gameM::renderer);
}
void ending::clean() {
	if (restart == true) {
		gameM::flag = true;
		gameM::current == gameM::stage1;
		allyLoader::get().reset();
	}
	
};