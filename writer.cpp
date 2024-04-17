#include "writer.h"
#include "gameM.h"

writer writer::typer;

writer& writer::get() {
	return typer;
}
void writer::loadText(std::string text, SDL_Color color) {
	font = TTF_OpenFont("D:\\vslib\\SDL2_ttf-2.22.0\\Arial.ttf", 12);
	SDL_Surface* txtSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* message = SDL_CreateTextureFromSurface(gameM::renderer, txtSurface);
	SDL_Rect msg = { 300, 250, 500,100 };
	SDL_RenderCopy(gameM::renderer, message, NULL, &msg);
	SDL_FreeSurface(txtSurface);
	SDL_DestroyTexture(message);
	message = NULL;
}

