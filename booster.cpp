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
		if (gameM::currentstage == gameM::stage1) boost[i].random(20, 40);
		else if (gameM::currentstage == gameM::stage2) boost[i].random(40, 60);
		msgbox[i] = { 100, 100 + 300 * i, 500, 200 };
		textbox[i] = { 200, 150 + 300 * i, 300 , 70 };
	}
	bg = IMG_LoadTexture(gameM::renderer, "resources\\bg2.jpg");
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
	SDL_RenderCopy(gameM::renderer, bg, NULL, NULL);
	for (int i = 0; i < 3; i++) {
		SDL_SetRenderDrawColor(gameM::renderer, 0xFD, 0xDA, 0x0D, 0xFF);
		SDL_RenderFillRect(gameM::renderer, &msgbox[i]);
		int w, h;
		TTF_SizeText(writer::get().font, boost[i].text.c_str(), &w, &h);
		std::cout << "size: " << w << " and " << h << std::endl;
		writer::get().loadText(boost[i].text /*+ extext*/, { 0xFF,0x00,0x00,0xFF }, textbox[i], 25);
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