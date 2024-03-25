#pragma once
#include "gameM.h"
//inherited by unit(ally) and enemy?
class image
{
public:
	image(int x, int y, int w, int h);
	image(int x, int y);
	image();
	~image();

	//set the object "texture" = "img";
	void set_image(SDL_Texture* img);

	//take w and h value from image texture
	void get_settings();

	// set blend mode
	void set_blendmode();

	void set_alpha(Uint8 alpha);
	void autorender();
	void render(SDL_Rect dst);

	void renderscrolling(int offset);

	bool inside();
	void flick_if_needed();

	void clean();
	SDL_Rect rect;
protected:

	SDL_Texture* texture;
	bool drawornot; // do i need this?

};
