
#include "commonfunc.h"
#include "BaseObject.h"
#include "unit.h"

SDL_Window* window = NULL;
SDL_Rect clips[4];

 // it won't work if it's not a pointer
TTF_Font* gFont = NULL;
SDL_Color txtcolor = { 255, 0 ,0 };

bool init() {
	bool status = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("can't init sdl, error %s", SDL_GetError());
		status = false;
	}
	else {
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		IMG_Init(IMG_INIT_PNG);
		if (TTF_Init() == -1) {
			printf("can't init TTF , error %s", TTF_GetError());
		}
	}
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		return status;
}
void close() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
int main(int argc, char* args[]) {
	if (!init()) printf("failed to init!");
	else
	{
		bool quit = false;
		unit hiyori;
		int frame = 0;
		hiyori.loadTexture("C:\\Users\\HUYBUIAN\\Downloads\\hiyori.png");
		hiyori.getsettings();
		//Event handler
		SDL_Event e;
		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				
			}
			SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);
			SDL_Rect currentClip = hiyori.clips[frame]; // clips[] does not work. pointer ???
			/*std::cout << currentClip.x << " " << currentClip.y << " " << currentClip.w << " " << currentClip.h << std::endl << std::endl;*/
			hiyori.render((SCREEN_WIDTH - hiyori.getframeWidth()) / 2, (SCREEN_HEIGHT - hiyori.getframeHeight()) / 2, &currentClip);
			std::cout << hiyori.getframeWidth() << " " << hiyori.getframeWidth() << std::endl;
			SDL_RenderPresent(renderer);
			frame++;
			if (frame >= 4) frame = 0;
		}
	}
	close();
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
