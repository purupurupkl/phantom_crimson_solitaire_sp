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
}
mainCombat::~mainCombat() {

}
void mainCombat::loadMedia() {
	currentturn = 0;
	bg = new image(0, 0);
	bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));

	for (int i = 0; i < 3; i++) {
		units[i] = new entity(i + 1);
		units[i]->loadEntityTexture();
		units[i]->set_rect(dst[i]);
	}
	for (int i = 3; i < 6; i++) {
		units[i] = new entity(-1);
		units[i]->loadEntityTexture();
		units[i]->set_rect(dst[i]);
	}
	

	//the numbers should be randomized from charSelect->loadmedia() and passed to maincombat->loadmedia 
	//load character 1/2/3 at pos 1/2/3 
	//charactercurrentstate = running (character will be running constantly when not fighting)
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
	
	if (e.type == SDL_MOUSEBUTTONDOWN) {

		for(int i = 3; i < 6; i++){
			if (units[i]->inside()) {
				printf("char2 touched\n");
				std::cout << units[i]->deadstt_getter() << std::endl;
				if (units[i]->deadstt_getter() == false) { // actually i should be checking health over here
				/*if (units[1]->atkstt_getter() == true) {*/
					units[i]->attacked(units[currentturn]->skill_cast());
					std::cout << "enemy " << i << "attacked" << units[i]->hp_getter() << std::endl;
					units[i]->hurtsttchange(true);
				}
				printf("next turn : character %i\n", currentturn + 1);
				break;
			}
		}
		
	}
}

void mainCombat::update() {
	//start: running
	//
	for (int i = 0; i < 6; i++) {
		if (units[i]->hurtstt_getter() == true) {
			//i should be checking health first
			//update health
			printf("%i\n", units[i]->hp_getter());
			if (units[i]->hp_getter() <= 0) {
				units[i]->deadsttchange(true);
				std::cout << units[3]->deadstt_getter() << std::endl;
			}
			units[currentturn]->attacksttchange(false);
			units[i]->hurtsttchange(false);
			currentturn = (currentturn + 1) % 3;
		}
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
	SDL_RenderClear(gameM::renderer);
	bg->renderscrolling(mainCombat::bgOffset);

	SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this
	//how to make it stop rendering after it has died?

	for (int i = 0; i < 6; i++) {
		if (units[i]->deadstt_getter() == false) {
			if (i == currentturn) {
				units[i]->renderEntity(dst[i], 1);
				units[i]->renderSkill();	
			}
			else units[i]->renderEntity(dst[i], 0);
		}
		else units[i]->renderEntity(outofscreen, 0);
	}
		
	// Render game objects, characters, backgrounds, etc.

	//render scrolling backround when charactercurrentstate != encounter


	//rendercharacter(int charactercurrentstate) will render character based on current state


	// Present the rendered frame to the screen
	SDL_RenderPresent(gameM::renderer);
}

void mainCombat::clean() {

}
