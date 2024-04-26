#include "writer.h"
#include "gameM.h"

writer writer::typer;

writer& writer::get() {
	return typer;
}
void writer::loadText(std::string text, SDL_Color color, SDL_Rect msg, int size) {
	SDL_Surface* txtSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	TTF_SetFontSize(font, size);
	SDL_Texture* message = SDL_CreateTextureFromSurface(gameM::renderer, txtSurface);
	SDL_RenderCopy(gameM::renderer, message, NULL, &msg);
	SDL_FreeSurface(txtSurface);
	SDL_DestroyTexture(message);
	message = NULL;
}
void writer::loadTextFlick(std::string text, SDL_Color color, SDL_Rect msg, int size, int alpha) {
	SDL_Surface* txtSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	TTF_SetFontSize(font, size);
	SDL_Texture* message = SDL_CreateTextureFromSurface(gameM::renderer, txtSurface);
	SDL_SetTextureAlphaMod(message, alpha);
	SDL_RenderCopy(gameM::renderer, message, NULL, &msg);
	SDL_FreeSurface(txtSurface);
	SDL_DestroyTexture(message);
	message = NULL;
}
void writer::loadTextWrapped(std::string text, SDL_Color color, SDL_Rect msg, int size, Uint32 wrap) {
	SDL_Surface* txtSurface = TTF_RenderText_Blended_Wrapped(font, text.c_str(), color, wrap);
	TTF_SetFontSize(font, size);
	SDL_Texture* message = SDL_CreateTextureFromSurface(gameM::renderer, txtSurface);
	SDL_RenderCopy(gameM::renderer, message, NULL, &msg);
	SDL_FreeSurface(txtSurface);
	SDL_DestroyTexture(message);
	message = NULL;
}

