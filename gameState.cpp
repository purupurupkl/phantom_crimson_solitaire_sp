#include "commonfunc.h"
#include "gameState.h"
gameState::gameState() {

}
gameState::~gameState()
{
}
void gameState::input(SDL_Event &e) {

}
void gameState::exit() {

}
void gameState::enter() {
		
}
 gameState* current = NULL;
 gameState* menuz = NULL;
 gameState* selector = NULL;
  
void gameState::shutdown() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		window = NULL;
		renderer = NULL;

		IMG_Quit();
		SDL_Quit();
}