#include "level1.h"
#include "allyLoader.h"
void level1::loadMedia() {
	currentturn = 0;
	bg = new image(0, 0);
	bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));
	allyLoader::get().realfren(ally);
	for (int i = 0; i < 3; i++) {
		ally[i]->loadEntityTexture();
		ally[i]->set_rect(dst[i]);
		std::cout << ally[i]->hp_getter() << std::endl;
	}
	for (int i = 0; i < 3; i++) {
		enemy[i] = new mob(-1);
		enemy[i]->loadEntityTexture();
		enemy[i]->set_rect(dst[i + 3]);
	}
}
void level1::eventHandler(SDL_Event e) {
	std::cout << "overriding eventhandler" << std::endl;
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (ally[currentturn]->anyskillchoosen()) {
				skillchoice = ally[currentturn]->choose_skill();
				skillchoosen = true;
			}
			else if (enemychoosen == false) {
				for (int i = 0; i < 3; i++) {
					if (enemy[i]->inside() && enemy[i]->dead == false) {
						std::cout << "enemy " << i << " choosen";
						enemychoosen = true;
						enemychoice = i;
						break;
					}
				}
			}
		}
		if (skillchoosen == true && enemychoosen == true) {
			enemy[enemychoice]->attacked(ally[currentturn]->skill_cast(skillchoice));
			std::cout << "enemy " << enemychoice << " was `attacked,remaining health " << enemy[enemychoice]->hp_getter() << std::endl;
			printf("next turn : character %i\n", currentturn + 1);
			turntaken = true;
		}
	
};

//void level1::render() {
//	SDL_RenderClear(gameM::renderer);
//	bg->renderscrolling(mainCombat::bgOffset);
//
//	SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this
//	for (int i = 0; i < 3; i++) {
//		if (ally[i]->dead == false) {
//			if (i == currentturn) {
//				ally[i]->renderEntity(1);
//				ally[i]->renderSkill();
//			}
//			else ally[i]->renderEntity(0);
//		}
//		else ally[i]->renderEntity(outofscreen, 0);
//		if (enemy[i]->dead == false) {
//			if (i == currentturn) {
//				enemy[i]->renderEntity(1);
//				enemy[i]->renderSkill();
//			}
//			else enemy[i]->renderEntity(0);
//		}
//		else enemy[i]->renderEntity(outofscreen, 0);
//	}
//	// Render game objects, characters, backgrounds, etc.
//
//	//render scrolling backround when charactercurrentstate != encounter ?
//
//	//rendercharacter(int charactercurrentstate) will render character based on current state ???
//	// Present the rendered frame to the screen
//	SDL_RenderPresent(gameM::renderer);
//	if (flag == true) {
//		gameM::current = gameM::main_menu;
//		flag = false;
//		SDL_RenderClear(gameM::renderer);
//	}
//	
//	
//}
