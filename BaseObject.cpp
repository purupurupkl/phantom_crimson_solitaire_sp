#include "commonfunc.h"
#include "BaseObject.h"
BaseObject::BaseObject() {

}
BaseObject::~BaseObject() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
}
void BaseObject::loadTexture(std::string path){
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	texture = newTexture;
}
void BaseObject::getsettings() {
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
		frameWidth = textureWidth / 4 /*COL_IN_SPRITE*/;
		frameHeight = textureHeight/*  ROW_IN_SPRITE*/;
}
void BaseObject::render(int x, int y, SDL_Rect* currentClip) {
	
	for (int i = 0; i < 4 /*FRAME_OF_SPRITE*/; i++) {
		clips[i].x = i * frameWidth;
		clips[i].y = 0;
		clips[i].w = frameWidth;
		clips[i].h = frameHeight;
	}
	SDL_Rect dest = { x, y, frameWidth,frameHeight};
	SDL_RenderCopy(renderer, texture, currentClip, &dest);
}
int BaseObject::getframeHeight() {
	return frameHeight;
}
int BaseObject::getframeWidth(){
	return frameWidth;
}

