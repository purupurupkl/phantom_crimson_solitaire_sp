#include "mainCombat.h"
#include "constants.h"
#include "allyLoader.h"
#include "writer.h"
#include <ctime>
//int mainCombat::bgOffset = 0;
mainCombat::mainCombat() {
	//all these rects and chars should be put in vectors or something
	srand(time(0));
	 
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

void mainCombat::update() {
	if (alive != 0) {
		if (frame == 0) {
			if (!myturn) {
				if (current->dead == false) {
					skillchoice = (current->available(1) == 1 ? 1 : 0);
					allychoice = enemyatk();
					//while (ally[allychoice]->dead == true) allychoice = rand() % 3;
					current->cast(skillchoice, ally[allychoice]);
					printf("next turn : character %i\n", allyturn + 1);
					turntaken = true;
				}
				else {
					turntaken = true;
					frame = 20;
				}
			}
		}
	}

	if (frame == 0) {
		if (turntaken == true) {
			current->update();
			skillchoice = -1;
			enemychoice = -1;
			allychoice = -1;
		}
	}
	int deadcount = 0;
	int quit = 0;
	for (int i = 0; i < 3; i++) {
		if (enemy[i]->dead == true) deadcount++;
		if (ally[i]->dead == true) quit++;
	}
	if (deadcount == 3) gameM::flag = true;
	if (quit == 3) {
		alive = 0;
		gameM::flag = true;
	}
	std::cout << "alive = " <<  alive << std::endl;
}

void mainCombat::render() {
	SDL_Color cl = { 0x00,0xFF,0x00,0xFF };
	SDL_RenderClear(gameM::renderer);
	//SDL_Rect bgsc = {300,200,300,300};
	SDL_RenderCopy(gameM::renderer, bg, NULL, NULL);
	SDL_Rect outofscreen = { 0, 0, 0, 0 };  // i can't interact with it anymore with this	
	SDL_Rect boardbox = { 50 ,800, 600, 200 };
	//render char icon here? 

	SDL_RenderCopy(gameM::renderer, board, NULL, &boardbox);

	if (turntaken == true)
	{
		if (current->dead == false) {
			current->aniEntity(1);
			current->renderSkill();
			frame++;
		}
		else current->renderEntity(outofscreen, 0);
		//turntaken = false, so current is definitely not dead (WRONG)
		if (myturn) {
			for (int i = 0; i < 3; i++) {
				if (i != allyturn) {
					if (ally[i]->dead == false) {
						ally[i]->renderEntity(0); //????
						ally[i]->renderHealth(dst[i]);
					}
					else ally[i]->renderEntity(outofscreen, 0);
				}
				if (enemy[i]->dead == false) {
					enemy[i]->renderEntity(0);
					enemy[i]->renderHealth(dst[i + 3]);
				}
				else enemy[i]->renderEntity(outofscreen, 0);
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				if (ally[i]->dead == false) {
					ally[i]->renderEntity(0); //????
					ally[i]->renderHealth(dst[i]);
				}
				else ally[i]->renderEntity(outofscreen, 0);

				if (i != enemyturn) {
					if (enemy[i]->dead == false) {
						enemy[i]->renderEntity(0);
						enemy[i]->renderHealth(dst[i + 3]);
					}
					else enemy[i]->renderEntity(outofscreen, 0);
				}
			}
		}
	}
	if (turntaken == false) {
		current->renderSkill();
		for (int i = 0; i < 3; i++) {
			if (ally[i]->dead == false) {
				ally[i]->renderEntity(0); //????
				ally[i]->renderHealth(dst[i]);
			}
			else ally[i]->renderEntity(outofscreen, 0);

			if (enemy[i]->dead == false) {
				enemy[i]->renderEntity(0);
				enemy[i]->renderHealth(dst[i + 3]);
			}
			else enemy[i]->renderEntity(outofscreen, 0);
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
			std::cout << "current ally is " << allyturn << std::endl;
		}
		else {
			enemyturn++;
			if (enemyturn == 3) {
				myturn = true;
				enemyturn = 0;
				current = ally[allyturn];
			}
			else current = enemy[enemyturn];
			std::cout << "current enemy is " << enemyturn << std::endl;
		}
		if (current->dead == false) { //check if next turn taker is dead. if alive reset
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