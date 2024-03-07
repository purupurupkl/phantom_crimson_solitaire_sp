#pragma once
#include "commonfunc.h"
extern SDL_Renderer* renderer;
class BaseObject
{
public:
	BaseObject();
	~BaseObject(); // constructor and destructor
	void loadTexture(std::string path);
	virtual void render(int x, int y, SDL_Rect* currentClip);
	void getsettings();
	int getframeWidth();
	int getframeHeight();
	SDL_Rect clips[4];
protected:
	SDL_Texture* texture;
	int frameHeight, frameWidth, textureHeight, textureWidth;
	//static int FRAME_OF_SPRITE = 4;
	int ROW_OF_SPRITE, COL_OF_SPRITE;
};
