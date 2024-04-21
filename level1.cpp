#include "level1.h"
#include "allyLoader.h"
void level1::loadMedia() {
	currentturn = 0;
	bg = IMG_LoadTexture(gameM::renderer, "C:\\Users\\HUYBUIAN\\Desktop\\resources maybe\\desert.jpeg");
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
	allyturn = 0;
	enemyturn = 0;
	frame = 0;
	myturn = true;
	current = ally[allyturn];
	
}
void level1::handlePlayer(SDL_Event &e) {
	switch (e.key.keysym.sym) {
	case SDLK_z:
		skillchoice = ally[currentturn]->available(0);
		break;
	case SDLK_x:
		skillchoice = ally[currentturn]->available(1);
		break;
	case SDLK_1:
		if (skillchoice != -1) enemychoice = 0; //what about dead enemy
		break;
	case SDLK_2:
		if (skillchoice != -1) enemychoice = 1;
		break;
	case SDLK_3:
		if (skillchoice != -1) enemychoice = 2;
		break;
	}
	if (skillchoice != -1) skillchoosen = true;
	if (enemychoice != -1) targetchoosen = true;
}
void level1::eventHandler(SDL_Event e){
	if (frame == 0) {					//while animation is NOT playing
		if (current->dead == false) { //turn requirement not met
			if (myturn) {
				if (e.type == SDL_KEYDOWN) {
					handlePlayer(e);
				}
			}
			else {
				skillchoice = 0;
				skillchoosen = true;
				allychoice = 0;
				while (ally[allychoice]->dead == true) allychoice = rand() % 3;
				targetchoosen = true;
			}
			if (skillchoosen == true && targetchoosen == true) {
				if (myturn) {
					current->cast(skillchoice, enemy[enemychoice]);
					std::cout << "enemy " << enemychoice << " was attacked,remaining health " << enemy[enemychoice]->hp_getter() << std::endl;
				}
				else {
					current->cast(skillchoice, ally[allychoice]);
					std::cout << "ally " << allychoice << " was attacked,remaining health " << ally[allychoice]->hp_getter() << std::endl;
				}
				printf("next turn : character %i\n", allyturn + 1);
				turntaken = true;
				skillchoosen = false;
				targetchoosen = false;
			}
		}
		else {
			turntaken = true;
			frame = 20;
		}
	}
};
void level1::update() {
		//if(!myturn){
		//	if (current->dead == false){
		//		if(frame == 0){
		//			skillchoice = 0;
		//			skillchoosen = true;
		//			allychoice = 0;
		//			while (ally[allychoice]->dead == true) allychoice = rand() % 3;
		//			targetchoosen = true;
		//		}
		//		if (skillchoosen == true && targetchoosen == true) {
		//			current->cast(skillchoice, ally[allychoice]);
		//			std::cout << "ally " << allychoice << " was attacked,remaining health " << ally[allychoice]->hp_getter() << std::endl;
		//		}
		//		printf("next turn : character %i\n", allyturn + 1);
		//		turntaken = true;
		//		skillchoosen = false;
		//		targetchoosen = false;
		//	}
		//}
		//else {
		//	turntaken = true;
		//	frame = 20;
		//}
	if (frame == 0) { 
		if (turntaken == true) {
			//for (int i = 0; i < 3; i++) {
			//	ally[i]->update();
			//	enemy[i]->update();
			//}//update everyone	
			current->update();
			skillchoice = -1;
			enemychoice = -1;
			allychoice = -1;
		}
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

		if(turntaken == true)
		{
			if (current->dead == false) {
				current->aniEntity(1);
				frame++;
			}
			else current->renderEntity(outofscreen, 0);
				//turntaken = false, so current is definitely not dead (WRONG)
			if (myturn) {
				for (int i = 0; i < 3; i++) {
					if (i != allyturn) {
						if (ally[i]->dead == false) {
							ally[i]->renderEntity(0); //????
							ally[i]->renderSkill();
							ally[i]->renderHealth(dst[i]);
						}
						else ally[i]->renderEntity(outofscreen, 0);
					}
					if (enemy[i]->dead == false) {
						enemy[i]->renderEntity(0);
						enemy[i]->renderSkill();
						enemy[i]->renderHealth(dst[i + 3]);
					}
					else enemy[i]->renderEntity(outofscreen, 0);
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					if (ally[i]->dead == false) {
						ally[i]->renderEntity(0); //????
						ally[i]->renderSkill();
						ally[i]->renderHealth(dst[i]);
					}
					else ally[i]->renderEntity(outofscreen, 0);

					if (i != enemyturn) {
						if (enemy[i]->dead == false) {
							enemy[i]->renderEntity(0);
							enemy[i]->renderSkill();
							enemy[i]->renderHealth(dst[i + 3]);
						}
						else enemy[i]->renderEntity(outofscreen, 0);
					}
				}
			}	
		}
		if (turntaken == false){                 
			for (int i = 0; i < 3; i++) {
				if (ally[i]->dead == false) {
					ally[i]->renderEntity(0); //????
					ally[i]->renderSkill();
					ally[i]->renderHealth(dst[i]);
				}
				else ally[i]->renderEntity(outofscreen, 0);

				if (enemy[i]->dead == false) {
					enemy[i]->renderEntity(0);
					enemy[i]->renderSkill();
					enemy[i]->renderHealth(dst[i + 3]);
				}
				else enemy[i]->renderEntity(outofscreen,0); 
				}
			}
		SDL_RenderPresent(gameM::renderer);
		if (turntaken == true && frame == 20) {
			if (myturn) {
				allyturn++;
				if (allyturn == 3) {
					myturn = false;
					allyturn = 0;
					current = enemy[enemyturn];
				}
				else current = ally[allyturn];
				std::cout << "current ally is" << allyturn << std::endl;
			}
			else {
				enemyturn++;
				if (enemyturn == 3) {
					myturn = true;
					enemyturn = 0;
					current = ally[allyturn];
				}
				else current = enemy[enemyturn];
				std::cout << "current enemy is" << enemyturn << std::endl;
			}
			if (current->dead == false) {
				turntaken = false;
				frame = 0;
			}
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