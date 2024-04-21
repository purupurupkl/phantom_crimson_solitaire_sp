#include "booster.h"
#include <cstdlib>
#include "gameM.h"
#include <string>
#include "writer.h"
#include "allyLoader.h"
booster::booster() {};
booster::~booster() {};
void booster::loadMedia() {
	for (int i = 0; i < 3; i++) {
		boost[i].atkmod = rand() % 30 + 1;
		boost[i].hpmod = rand() % 50 + 1;
		msgbox[i] = { 0, 100 + 300 * i, 600, 200 };
		textbox[i] = { 50, 150 + 300 * i, 500,100 };
		text[i] = "Your team gain " + std::to_string(boost[i].atkmod) + " ATK and " + std::to_string(boost[i].hpmod);
	}
}
bool inside(SDL_Rect box) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect mousenow = { x,y,1,1 };
	bool inside = SDL_HasIntersection(&mousenow, &box);
	return inside;
}
void booster::eventHandler(SDL_Event e) {
	
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		for (int i = 0; i < 3; i++) {
			if (inside(msgbox[i])) {
				allyLoader::get().applyCard(boost[i].atkmod,boost[i].hpmod);
				gameM::flag = true;
			}
		}
	}
	

}
void booster::render() {
	std::string extext = "I'm sorry this looks so bad, calculus messed with me so hard yo";
	SDL_RenderClear(gameM::renderer);
	for (int i = 0; i < 3; i++) {
		SDL_SetRenderDrawColor(gameM::renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(gameM::renderer, &msgbox[i]);
		writer::get().loadText(text[i] + extext, { 0xFF,0x00,0x00,0xFF }, textbox[i], 20);
	}
	SDL_RenderPresent(gameM::renderer);
	
}
void booster::update(){
	
}
void booster::clean(){
	if (gameM::flag == true) gameM::current = gameM::stage2;
}