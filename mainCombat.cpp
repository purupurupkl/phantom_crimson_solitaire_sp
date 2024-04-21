#include "mainCombat.h"
#include "constants.h"
#include "allyLoader.h"
#include "writer.h"
#include <ctime>
//int mainCombat::bgOffset = 0;
mainCombat::mainCombat() {
	//all these rects and chars should be put in vectors or something
	srand(time(0));
	 dst[0] = { 100, 300, 150, 150};
	 dst[1] = { 150, 350, 150, 150};
	 dst[2] = { 100, 400, 200, 126};


	 dst[3] = {300, 300, 150, 150};
	 dst[4] = {250, 350, 150, 150};
	 dst[5] = {300, 400, 150, 150};
	 currentturn = 0;
	 enemychoosen = false;
	 skillchoosen = false;
	 turntaken = false;
	 enemychoice = -1;
	 allychoice = -1;
	 skillchoice = -1;
	 frame = 0;
	 //flag = false;
}
mainCombat::~mainCombat() {

}
void mainCombat::loadMedia() {
	currentturn = 0;
	bg = IMG_LoadTexture(gameM::renderer, "C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg");
	//bg = new image(0, 0);
	//bg->set_image(loader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));
	allyLoader::get().realfren(ally);
	for (int i = 0; i < 3; i++) {
		//ally[i] = new fren(1);
		std::cout << ally[i]->sprite[1] << std::endl;	
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

void mainCombat::eventHandler(SDL_Event e){
	if (currentturn >= 3) {
		if (enemy[currentturn - 3]->dead == false) {
			skillchoice = 1;
			do {
				allychoice = rand() % 3;
			} while (ally[allychoice]->dead == true);
			ally[allychoice]->attacked(enemy[currentturn - 3]->skill_cast(skillchoice));
			std::cout << "ally " << allychoice << " was attacked,remaining health " << ally[allychoice]->hp_getter() << std::endl;
			turntaken = true;
		}
		else currentturn = (currentturn + 1) % 6;
		printf("next turn : character %i\n", currentturn + 1);
		//SDL_Delay(5000);
	}
	else{
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (skillchoosen == false) {
				skillchoice = ally[currentturn]->availableSkill();
				if (skillchoice != -1) {
					skillchoosen = true;
					ally[currentturn]->abi[skillchoice].choosen = true;
				}
			}
			else if (enemychoosen == false) {
				for (int i = 0; i < 3; i++) {
					if (enemy[i]->inside()){
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
			std::cout << "enemy " << enemychoice << " was attacked,remaining health " << enemy[enemychoice]->hp_getter() << std::endl;
			printf("next turn : character %i\n", currentturn + 1);
			turntaken = true;
		}
	}
}

void mainCombat::update() {
	//start: running
	//
	if (turntaken == true) {
		for (int i = 0; i < 3; i++) {
			ally[i]->update();
			enemy[i]->update();
		}//update everyone
	}
	int deadcount = 0;
	for (int i = 0; i < 3; i++) {
		if (enemy[i]->dead == true) deadcount++;
		
	}
	std::cout << "total number of death is now " << deadcount << std::endl;
	if (deadcount == 3) gameM::flag = true;
}

void mainCombat::render() {
	//SDL_Color cl = { 0x00,0xFF,0x00,0xFF };
	//for (int j = 0; j < 40; j++) {
	//	SDL_RenderClear(gameM::renderer);
	//	SDL_Rect bgsc = { 0,0,600, 825 };
	//	SDL_RenderCopy(gameM::renderer, bg, &bgsc, NULL);
	//	SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this
	//	for (int i = 0; i < 3; i++) {
	//		if (ally[i]->dead == false) {
	//			if (i == currentturn) {
	//				if (turntaken == true) {
	//					ally[i]->aniEntity(1, j / 2);
	//				}
	//				else ally[i]->renderEntity(dst[i], 0); //????
	//				ally[i]->renderSkill();
	//			}
	//			else ally[i]->renderEntity(0);
	//			ally[i]->renderHealth(dst[i]);
	//		}
	//		else ally[i]->renderEntity(outofscreen, 0);
	//		if (enemy[i]->dead == false) {
	//			if (i + 3 == currentturn) {
	//				enemy[i]->renderEntity(dst[i + 3], 1);
	//				enemy[i]->renderSkill();
	//			}
	//			else enemy[i]->renderEntity(0);
	//			enemy[i]->renderHealth(dst[i + 3]);
	//		}
	//		else {
	//			enemy[i]->renderEntity(outofscreen, 0);
	//		}
	//	}
	//	SDL_RenderPresent(gameM::renderer);
	//}
	//	/*ally[0]->renderEntity(1, i);
	//	ally[1]->renderEntity(1, i);
	//	ally[2]->renderEntity(1, i);
	//	SDL_RenderPresent(gameM::renderer);*/
	////}
}

void mainCombat::clean() {
	
}