#pragma once
#include "entity.h"
class allyLoader
{
public:
	static allyLoader& get();
	void initAlly();
	void realfren(fren* ally[3]);
	void applyCard(int,int);
	void reset();
	fren* rAlly[3];
private:
	
	allyLoader() {};
	static allyLoader cally;
};

