#include "mainCombat.h"
#include "constants.h"
#include "allyLoader.h"
#include "writer.h"
#include <ctime>
//int mainCombat::bgOffset = 0;
mainCombat::mainCombat() {
	//all these rects and chars should be put in vectors or something
	srand(time(0));
	 targetchoosen = false;
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
int mainCombat::enemyatk() {
	int choice = 0;
	int maxhp = 0;
	for (int i = 0; i < 3; i++) {
		if (ally[i]->stats.hp >= maxhp) {
			choice = i;
			maxhp = ally[i]->stats.hp;
		}
	}
	return choice;
}
//void mainCombat::loadMedia() {
//	currentturn = 0;
//	bg = IMG_LoadTexture(gameM::renderer, "C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg");
//	//bg = new image(0, 0);
//	//bg->set_image(loader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));
//	allyLoader::get().realfren(ally);
//	for (int i = 0; i < 3; i++) {
//		//ally[i] = new fren(1);
//		std::cout << ally[i]->sprite[1] << std::endl;	
//		ally[i]->loadEntityTexture();
//		ally[i]->set_rect(dst[i]);
//	}
//	for (int i = 0; i < 3; i++) {
//		enemy[i] = new mob(-1);
//		enemy[i]->loadEntityTexture();
//		enemy[i]->set_rect(dst[i + 3]);
//	}
//}
//
//void mainCombat::eventHandler(SDL_Event e){
//	
//}
//
//void mainCombat::update() {
//	//start: running
//	//
//	if (turntaken == true) {
//		for (int i = 0; i < 3; i++) {
//			ally[i]->update();
//			enemy[i]->update();
//		}//update everyone
//	}
//	int deadcount = 0;
//	for (int i = 0; i < 3; i++) {
//		if (enemy[i]->dead == true) deadcount++;
//		
//	}
//	std::cout << "total number of death is now " << deadcount << std::endl;
//	if (deadcount == 3) gameM::flag = true;
//}
//
//void mainCombat::render() {
//	//SDL_Color cl = { 0x00,0xFF,0x00,0xFF };
//	//for (int j = 0; j < 40; j++) {
//	//	SDL_RenderClear(gameM::renderer);
//	//	SDL_Rect bgsc = { 0,0,600, 825 };
//	//	SDL_RenderCopy(gameM::renderer, bg, &bgsc, NULL);
//	//	SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this
//	//	for (int i = 0; i < 3; i++) {
//	//		if (ally[i]->dead == false) {
//	//			if (i == currentturn) {
//	//				if (turntaken == true) {
//	//					ally[i]->aniEntity(1, j / 2);
//	//				}
//	//				else ally[i]->renderEntity(dst[i], 0); //????
//	//				ally[i]->renderSkill();
//	//			}
//	//			else ally[i]->renderEntity(0);
//	//			ally[i]->renderHealth(dst[i]);
//	//		}
//	//		else ally[i]->renderEntity(outofscreen, 0);
//	//		if (enemy[i]->dead == false) {
//	//			if (i + 3 == currentturn) {
//	//				enemy[i]->renderEntity(dst[i + 3], 1);
//	//				enemy[i]->renderSkill();
//	//			}
//	//			else enemy[i]->renderEntity(0);
//	//			enemy[i]->renderHealth(dst[i + 3]);
//	//		}
//	//		else {
//	//			enemy[i]->renderEntity(outofscreen, 0);
//	//		}
//	//	}
//	//	SDL_RenderPresent(gameM::renderer);
//	//}
//	//	/*ally[0]->renderEntity(1, i);
//	//	ally[1]->renderEntity(1, i);
//	//	ally[2]->renderEntity(1, i);
//	//	SDL_RenderPresent(gameM::renderer);*/
//	////}
//}
//
//void mainCombat::clean() {
//	
//}