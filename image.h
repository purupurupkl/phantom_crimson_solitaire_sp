#pragma once
#include "gameM.h"
class image
{
public:
	image(int x, int y, int w, int h);
	image(int x, int y);
	image();
	~image();

	//set the object "texture" = "img";
	void set_image(SDL_Texture* img);
	void set_imagepos(SDL_Rect& imgpos);

	// set blend mode
	void set_blendmode();

	void set_alpha(Uint8 alpha);
	void autorender();
	void autoanimate(/*int frame*/);
	void render(SDL_Rect dst);
	//void renderscrolling(int offset);
	bool inside();
	void flick_if_needed();

	void clean();
	int textureWidth; int textureHeight;
	int frameWidth;  int frameHeight;	
	SDL_Rect sc[20];
protected:
	int frame;
	SDL_Rect rect;
	SDL_Texture* texture;
};
