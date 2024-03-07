#include "unit.h"
//unit constructor

unit::unit()
{
}

//unit destructor
unit::~unit()
{

}
void unit::render(int x, int y, SDL_Rect* currentClip) {

	for (int i = 0; i < 4 /*FRAME_OF_SPRITE*/; i++) {
		clips[i].x = i * frameWidth;
		clips[i].y = 0;
		clips[i].w = frameWidth;
		clips[i].h = frameHeight;
	}
	SDL_Rect dest = {x, y, 64,94};
	SDL_RenderCopy(renderer, texture, currentClip, &dest);
}
void unit::ActionHandler(SDL_Event event) {

}
