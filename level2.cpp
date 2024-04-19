#include "level2.h"
#include "allyLoader.h"
void level2::loadMedia() {
		currentturn = 0;
		bg = IMG_LoadTexture(gameM::renderer, "C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\redder.jpeg");
		allyLoader::get().realfren(ally);
		std::cout << " loaded level 2 " << std::endl;
		for (int i = 0; i < 3; i++) {
			//ally[i] = new fren(1);
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
void level2::render() {
	SDL_Color cl = { 0x00,0xFF,0x00,0xFF };
	for (int j = 0; j < 40; j++) {
		SDL_RenderClear(gameM::renderer);
		SDL_Rect bgsc = { 0,0,600, 825 };
		SDL_RenderCopy(gameM::renderer, bg, &bgsc, NULL);
		SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this
		for (int i = 0; i < 3; i++) {
			if (ally[i]->dead == false) {
				if (i == currentturn) {
					if (turntaken == true) {
						ally[i]->aniEntity(1, j / 2);
					}
					else ally[i]->renderEntity(dst[i], 0); //????
					ally[i]->renderSkill();
				}
				else ally[i]->renderEntity(0);
				ally[i]->renderHealth(dst[i]);
			}
			else ally[i]->renderEntity(outofscreen, 0);
			if (enemy[i]->dead == false) {
				if (i + 3 == currentturn) {
					enemy[i]->renderEntity(dst[i + 3], 1);
				}
				else enemy[i]->renderEntity(0);
				enemy[i]->renderHealth(dst[i + 3]);
			}
			else {
				enemy[i]->renderEntity(outofscreen, 0);
			}
		}
		SDL_RenderPresent(gameM::renderer);
	}
	/*ally[0]->renderEntity(1, i);
	ally[1]->renderEntity(1, i);
	ally[2]->renderEntity(1, i);
	SDL_RenderPresent(gameM::renderer);*/
	//}
}

