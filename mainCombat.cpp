#include "mainCombat.h"
#include "constants.h"
#include "allyLoader.h"
#include "writer.h"
#include <ctime>
int mainCombat::bgOffset = 0;
mainCombat::mainCombat() {
	//all these rects and chars should be put in vectors or something
	srand(time(0));
	 dst[0] = {100, 300, 90, 90};
	 dst[1] = { 100, 500, 90, 90 };
	 dst[2] = { 200, 400, 90, 90 };


	 dst[3] = { 1000, 300, 90, 90 };
	 dst[4] = {1000, 500, 90, 90};
	 dst[5] = {950, 400, 90, 90};
	 currentturn = 0;
	 enemychoosen = false;
	 skillchoosen = false;
	 turntaken = false;
	 skillchoice = -1;
	 enemychoice = -1;
	 allychoice = -1;
	 flag = false;
}
mainCombat::~mainCombat() {

}
void mainCombat::loadMedia() {
	currentturn = 0;
	bg = new image(0, 0);
	bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));
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
	
	//the numbers should be randomized from charSelect->loadmedia() and passed to maincombat->loadmedia 
	//load character 1/2/3 at pos 1/2/3 
	//charactercurrentstate = running (character will be running constantly when not fighting?)
	// 
	// basicallythe idea is to load EVERY SINGLE IMAGE into a container and draw them to the screen when needed 
	// 
}

void mainCombat::eventHandler(SDL_Event e) {
	if (currentturn >= 3) {
		skillchoice = 1;
		do {
			allychoice = rand() % 3;
		} while (ally[allychoice]->dead == true);
		ally[allychoice]->attacked(enemy[currentturn - 3]->skill_cast(skillchoice));
		std::cout << "ally " << allychoice << " was attacked,remaining health " << ally[allychoice]->hp_getter() << std::endl;
		turntaken = true;
		printf("next turn : character %i\n", currentturn + 1);
		//SDL_Delay(5000);
	}
	else{
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (ally[currentturn]->anyskillchoosen()) {
				skillchoice = ally[currentturn]->choose_skill();
				skillchoosen = true;
			}
			else if (enemychoosen == false) {
				for (int i = 0; i < 3; i++) {
					if (enemy[i]->inside() && enemy[i]->dead == false){
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
	if (skillchoosen == true && enemychoosen == true && turntaken == true) {
		if (enemy[enemychoice]->hp_getter() <= 0) {
			enemy[enemychoice]->dead = true;
			std::cout << "rip bozo" << std::endl;
			enemychoice = -1;
		}
		skillchoosen = false;
		enemychoosen = false;
		currentturn = (currentturn + 1) % 6;
		for (int i = 0; i < 3; i++) {
			std::cout << std::endl << ally[i]->hp_getter() << " ";
		}
		std::cout << std::endl;
		turntaken = false;
	}
	else if (turntaken == true) {
		if (ally[allychoice]->hp_getter() <= 0) {
			ally[allychoice]->dead = true;
			std::cout << "someone died" << std::endl;
			allychoice = -1;
		}
		currentturn = (currentturn + 1) % 6;
		turntaken = false;
	}
	
	bgOffset -= bgScrollSpeed;
	if (bgOffset <= -SCREEN_WIDTH) {
		bgOffset = 0;
	}
	//should the character state (idle,attack, run, dead) be updated here?
	//gonna be one plethora of ifs huh
}

void mainCombat::render() {
	// Clear the screen
	SDL_Color cl = { 0x00,0xFF,0x00,0xFF };
	
	SDL_RenderClear(gameM::renderer);
	bg->renderscrolling(mainCombat::bgOffset);

	SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this

	for (int i = 0; i < 3; i++) {
		if (ally[i]->dead == false) {
			if (i == currentturn) {
				ally[i]->renderEntity(1);
				ally[i]->renderSkill();	
			}
			else ally[i]->renderEntity(0);
		}
		else ally[i]->renderEntity(outofscreen, 0);
		if (enemy[i]->dead == false) {
			if (i == currentturn) {
				enemy[i]->renderEntity(1);
				enemy[i]->renderSkill();
			}
			else enemy[i]->renderEntity(0);
		}
		else enemy[i]->renderEntity(outofscreen, 0);
	}
	SDL_RenderPresent(gameM::renderer);
}

void mainCombat::clean() {
	
}