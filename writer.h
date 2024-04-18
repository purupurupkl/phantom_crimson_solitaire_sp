#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
class writer
{
public:
	static writer& get();
	void loadText(std::string text, SDL_Color txtColor, SDL_Rect msg);
	TTF_Font* font;
private:
	writer() {};
	static writer typer;
};

