#include "level1.h"
#include "allyLoader.h"
void level1::loadMedia() {
	currentturn = 0;
	bg = IMG_LoadTexture(gameM::renderer, "C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg");
	//bg->set_imagepos();
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
		if (currentturn >= 3) {
			if (/*enemy[currentturn - 3]->dead == false*/true ) {
				skillchoice = 1;
				do {
					allychoice = rand() % 3;
				} while (ally[allychoice]->dead == true);
				ally[allychoice]->attacked(enemy[currentturn - 3]->skill_cast(skillchoice));
				std::cout << "ally " << allychoice << " was attacked,remaining health " << ally[allychoice]->hp_getter() << std::endl;	
				std::cout << allyLoader::get().rAlly[allychoice]->hp_getter() << " HP OF TRUE FRIEND " << std::endl;
			}
		turntaken = true;
		printf("next turn : character %i\n", (currentturn + 1) % 6);
		//SDL_Delay(5000);
		}
		else {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (skillchoosen == false || ally[currentturn]->availableSkill() != -1) {
					skillchoice = ally[currentturn]->availableSkill();
					if (skillchoice != -1) {
						skillchoosen = true;
						std::cout << "skill choosen: " << skillchoice << std::endl;
					}
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
		}
		if (skillchoosen == true && enemychoosen == true) {
			ally[currentturn]->abi[skillchoice].choosen = true;
			enemy[enemychoice]->attacked(ally[currentturn]->skill_cast(skillchoice));
			std::cout << "enemy " << enemychoice << " was attacked,remaining health " << enemy[enemychoice]->hp_getter() << std::endl;
			printf("next turn : character %i\n", (currentturn + 1) % 6);
			turntaken = true;
			skillchoosen = false;
			enemychoosen = false;
		}
	
};
void level1::update() {
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
	if (deadcount == 3) gameM::flag = true;
}
void level1::render() {
	SDL_Color cl = { 0x00,0xFF,0x00,0xFF };
	//int fps = 5;
	//Uint32 elapsed = 0;
	//int frametime = 0;
	//elapsed = SDL_GetTicks();
		SDL_RenderClear(gameM::renderer);
		SDL_Rect bgsc = { 0,0,600, 825 };
		SDL_RenderCopy(gameM::renderer, bg, &bgsc, NULL);
		SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this
		for (int i = 0; i < 3; i++) {
			if (ally[i]->dead == false) {
				if (i == currentturn) {
					if (turntaken == true && frame < 20) {
						ally[i]->aniEntity(1);
						frame++;
					}
					else ally[i]->aniEntity(0); //????
					ally[i]->renderSkill();
				}
				else ally[i]->aniEntity(0);
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
		if (turntaken == true && frame == 20) {
			ally[currentturn]->abi[skillchoice].choosen = false;
			enemychoice = -1;
			currentturn = (currentturn + 1) % 6;
			std::cout << "next turn is " << currentturn << std::endl;
			allychoice = -1;
			turntaken = false;
			frame = 0;
		}
		//at enemy turn, frame is not incremented, hence the loop of enemy4
			
		//frametime = SDL_GetTicks() - elapsed;
		//if (1000 / fps > frametime) SDL_Delay((1000 / fps) - frametime);
		
	//set turntaken to false later + reset frame
	// maybe not creating every texture right away?
}
		
void level1::clean() {
	if (gameM::flag == true) {
		SDL_DestroyTexture(bg);
		bg = NULL;
		/*for (int i = 0; i < 3; i++) {
			enemy[i]->~mob();
			ally[i]->~fren();
			delete enemy[i];
			delete ally[i];
		}*/
		gameM::current = gameM::after1;
	}

}