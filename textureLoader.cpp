
#include "textureLoader.h"
SDL_Texture* textureLoader::loadTexture(const char* name) {
	SDL_Texture* tempTexture;
	tempTexture = IMG_LoadTexture(gameM::renderer, name);
	return tempTexture;
}