#include "mainCombat.h"
#include "constants.h"
int mainCombat::bgOffset = 0;
mainCombat::mainCombat() {
	//all these rects and chars should be put in vectors or something
	
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
}
mainCombat::~mainCombat() {

}
void mainCombat::loadMedia() {
	currentturn = 0;
	bg = new image(0, 0);
	bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));

	for (int i = 0; i < 3; i++) {
		ally[i] = new entity(1);
		ally[i]->loadEntityTexture();
		ally[i]->set_rect(dst[i]);
	}
	for (int i = 0; i < 3; i++) {
		enemy[i] = new entity(-1);
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
	//switch(e.type){
	//	// when charactercurrentstate = encounter;
	//	// case char1/2/3 touched
	//	// drawmenu = true;
	//	// case menu 1/2/3 touched 
	//	// write "choose target" ** for later**
	//	// case enemy 1/2/3 touched 

	// turn based: press on ally -> ally chosen (like below); press on enemy, enemy chosen; press on another enemy: function changetarget()? on entity class/on combat class/on the vector class (vector of entity)
	//}	
	if (currentturn >= 3) {
		skillchoice = enemy[currentturn - 3]->enemy_skill();
		allychoice = 0;
		/*while (ally[allychoice]->dead == true) {
			allychoice++;
		}*/
		ally[allychoice]->attacked(enemy[currentturn - 3]->skill_cast(skillchoice));
		std::cout << "ally " << allychoice << " attacked,remaining health " << ally[allychoice]->hp_getter() << std::endl;
		/*ally[allychoosen]->hurtsttchange(true);*/
		turntaken = true;
		printf("next turn : character %i\n", currentturn + 1);
		//SDL_Delay(5000);
	}
	else{
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (/*enemychoosen == false && */ally[currentturn]->anyskillchoosen()) {
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
			std::cout << "enemy " << enemychoice << " attacked,remaining health " << enemy[enemychoice]->hp_getter() << std::endl;
			enemy[enemychoice]->hurtsttchange(true);
			printf("next turn : character %i\n", currentturn + 1);
			turntaken = true;
		}
	}

	

		
}

void mainCombat::update() {
	//start: running
	//
	if (turntaken == true) {
		if (enemy[enemychoice]->hp_getter() <= 0) {
			enemy[enemychoice]->dead = true;
			std::cout << "rip bozo" << std::endl;
			enemychoice = -1;
		}
		if (ally[allychoice]->hp_getter() <= 0) {
			ally[allychoice]->dead = true;
			std::cout << "someone died" << std::endl;
			allychoice = -1;
		}
		skillchoosen = false;
		enemychoosen = false;
		currentturn = (currentturn + 1) % 6;
		turntaken = false;
	}
	//for (int i = 0; i < 3; i++) {
	//	if (enemy[i]->hurtstt_getter() == true) {
	//		//i should be checking health first
	//		//update health
	//		printf("%i\n", enemy[i]->hp_getter());
	//		
	//		enemy[currentturn]->attacksttchange(false);
	//		enemy[i]->hurtsttchange(false);
	//		currentturn = (currentturn + 1) % 6;
	//		
	//	}
	//}
	//for (int i = 0; i < 3; i++) {
	//	if (ally[i]->hurtstt_getter() == true) {
	//		//i should be checking health first
	//		//update health
	//		printf("%i\n", ally[i]->hp_getter());
	//		if (ally[i]->hp_getter() <= 0) {
	//			ally[i]->dead = true;
	//			
	//		}
	//		ally[currentturn]->attacksttchange(false);
	//		ally[i]->hurtsttchange(false);
	//		currentturn = (currentturn + 1) % 6;
	//		skillchoosen = false;
	//		enemychoosen = false;
	//	}
	//}
	bgOffset -= bgScrollSpeed;
	if (bgOffset <= -SCREEN_WIDTH) {
		bgOffset = 0;
	}
	
	//should the character state (idle,attack, run, dead) be updated here?
	//gonna be one plethora of ifs huh
}

void mainCombat::render() {
	// Clear the screen
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
		
	// Render game objects, characters, backgrounds, etc.

	//render scrolling backround when charactercurrentstate != encounter ?


	//rendercharacter(int charactercurrentstate) will render character based on current state


	// Present the rendered frame to the screen
	SDL_RenderPresent(gameM::renderer);
}

void mainCombat::clean() {

}
