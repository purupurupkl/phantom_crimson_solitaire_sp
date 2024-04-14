#include "textureLoader.h"
SDL_Texture* textureLoader::loadTexture(const char* name) {
	std::cout << "now loading texture " << std::endl;
	SDL_Texture* tempTexture;
	tempTexture = IMG_LoadTexture(gameM::renderer, name);
	if (tempTexture == NULL) printf("error loading texture: %s", IMG_GetError()); //check
	return tempTexture;
}