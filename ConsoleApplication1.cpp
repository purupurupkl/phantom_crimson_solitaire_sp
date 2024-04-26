	
#include "gameM.h"
#include "entity.h"
#include "allyLoader.h";

int main(int argc, char* argv[])
{
	int fps = 30;
	Uint32 elapsed = 0;
	int frametime = 0;

	gameM* game = new gameM();
	if (game->init()) {	
		allyLoader::get().initAlly();
		
		while (!gameM::quit) {
			elapsed = SDL_GetTicks();
			game->loadMedia();
			SDL_Event e;
			while (SDL_PollEvent(&e)) {
				game->eventHandler(e);
			}
			game->update();
			game->render();
			game->clean();
			frametime = SDL_GetTicks() - elapsed;
			if (1000 / fps > frametime) SDL_Delay((1000 / fps) - frametime);
		}
	}
	delete game;
	return 0;
}

// no commandline argument = error???

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
