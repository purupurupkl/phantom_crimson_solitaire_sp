#include "mainCombat.h"
#include "constants.h"
int mainCombat::bgOffset = 0;
mainCombat::mainCombat() {

}
mainCombat::~mainCombat() {

}
void mainCombat::loadMedia() {
	bg = new image(0, 0);
	bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));
	char1 = new entity(1);
	char2 = new entity(2);
	char3 = new entity(3);
	char1->loadEntityTexture();
	char2->loadEntityTexture();
	char3->loadEntityTexture();

	enemy1 = new entity(-1);
	enemy2 = new entity(-1);
	enemy3 = new entity(-1);
	enemy1->loadEntityTexture();
	enemy2->loadEntityTexture();
	enemy3->loadEntityTexture();
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
		if (char1->image_getter()->inside()) {
			char1->attacksttchange(true);
			std::cout << "char1 touched " << char1->atkstt_getter() << std::endl;
		}
		if (enemy1->image_getter()->inside()) {
			printf("char2 touched\n");
			std::cout << enemy1->deadstt_getter() << std::endl;
			if (enemy1->deadstt_getter() == false) { // actually i should be checking health over here
				if (char1->atkstt_getter() == true) {
					enemy1->attacked(50);
					enemy1->hurtsttchange(true);
				}
			}
		}
	}
}

void mainCombat::update() {
	//start: running
	//
	if (enemy1->hurtstt_getter() == true) {
		//i should be checking health first
		//update health
		printf("%i\n", enemy1->hp_getter());
		if (enemy1->hp_getter() <= 0) {
			enemy1->deadsttchange(true);
			std::cout << enemy1->deadstt_getter() << std::endl;
		}
		char1->attacksttchange(false);
		enemy1->hurtsttchange(false);
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


	//all these rects and chars should be put in vectors or something
	SDL_Rect dst1 = { 100, 300, 90, 90 };
	SDL_Rect dst2 = { 100, 500, 90, 90 };
	SDL_Rect dst3 = { 200, 400, 90, 90 };


	SDL_Rect dst4 = { 1000, 300, 90, 90 };
	SDL_Rect dst5 = { 1000, 500, 90, 90 };
	SDL_Rect dst6 = { 950, 400, 90, 90 };

	SDL_Rect outofscreen = { 0,0, 0, 0 };  // i can't interact with it anymore with this
	//how to make it stop rendering after it has died?
	char1->renderEntity(dst1);
	char2->renderEntity(dst2);
	char3->renderEntity(dst3);

	if (enemy1->deadstt_getter() == false) {
		enemy1->renderEntity(dst4);
	}
	else enemy1->renderEntity(outofscreen);

	enemy2->renderEntity(dst5);
	enemy3->renderEntity(dst6);

	// Render game objects, characters, backgrounds, etc.

	//render scrolling backround when charactercurrentstate != encounter


	//rendercharacter(int charactercurrentstate) will render character based on current state


	// Present the rendered frame to the screen
	SDL_RenderPresent(gameM::renderer);



}

void mainCombat::clean() {

}
