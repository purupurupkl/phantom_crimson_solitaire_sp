#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
class writer
{
public:
	static writer& get();
	void loadText(std::string text, SDL_Color txtColor, SDL_Rect msg, int size);
	void loadTextWrapped(std::string text, SDL_Color txtColor, SDL_Rect msg, int size, Uint32 wrap);
	void loadTextFlick(std::string text, SDL_Color color, SDL_Rect msg, int size, int alpha);
	TTF_Font* font;
private:
	writer() {};
	static writer typer;
};

