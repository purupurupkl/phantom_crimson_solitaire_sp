#pragma once
#include "gameM.h"
class textureLoader
{
public:

	//return a texture from an image file
	static SDL_Texture* loadTexture(const char* name);


	//static SDL_Texture* loadScrollingBg(const char* name);
};


