#pragma once
#include "entity.h"
class allyLoader
{
public:
	static allyLoader& get();
	void initAlly();
	void realfren(fren* ally[3]);
	void applyCard(int,int);
	fren* rAlly[3];
private:
	
	allyLoader() {};
	static allyLoader cally;
};

