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
		boost[i].random(30, 50);
		msgbox[i] = { 0, 100 + 300 * i, 600, 200 };
		textbox[i] = { 100, 150 + 300 * i, 300 , 100 };
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
	SDL_SetRenderDrawColor(gameM::renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(gameM::renderer);
	for (int i = 0; i < 3; i++) {
		SDL_SetRenderDrawColor(gameM::renderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(gameM::renderer, &msgbox[i]);
		int w, h;
		TTF_SizeText(writer::get().font, boost[i].text.c_str(), &w, &h);
		std::cout << "size: " << w << " and " << h << std::endl;
		writer::get().loadTextWrapped(boost[i].text /*+ extext*/, { 0xFF,0x00,0x00,0xFF }, textbox[i], 25, 200);
	}
	SDL_RenderPresent(gameM::renderer);
	
}
void booster::update(){
	
}
void booster::clean(){
	if (gameM::flag == true) {
		switch (gameM::currentstage) {
		case 1:
			gameM::current = gameM::stage2;
			break;
		case 2:
			gameM::current = gameM::stage3;
			break;
		}
	}

}