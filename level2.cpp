#include "level2.h"
#include "allyLoader.h"
void level2::loadMedia() {
		currentturn = 0;
		bg = new image(0, 0);
		bg->set_image(textureLoader::loadTexture("C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\redder.jpg"));
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
};

