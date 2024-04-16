#include "level2.h"
void level2::loadMedia() {
		currentturn = 0;
		bg = new image(0, 0);
		bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg"));

		for (int i = 0; i < 3; i++) {
			ally[i] = new fren(1);
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
};

