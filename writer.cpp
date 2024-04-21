#include "writer.h"
#include "gameM.h"

writer writer::typer;

writer& writer::get() {
	return typer;
}
void writer::loadText(std::string text, SDL_Color color, SDL_Rect msg, int size) {
	SDL_Surface* txtSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
	TTF_SetFontSize(font, size);
	SDL_Texture* message = SDL_CreateTextureFromSurface(gameM::renderer, txtSurface);
	SDL_RenderCopy(gameM::renderer, message, NULL, &msg);
	SDL_FreeSurface(txtSurface);
	SDL_DestroyTexture(message);
	message = NULL;
}

