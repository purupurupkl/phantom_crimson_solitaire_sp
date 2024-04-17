#pragma once
#include "entity.h"
class allyLoader
{
public:
	static allyLoader& get();
	void initAlly();
	void realfren(fren* ally[3]);
	void allUpdate();
private:
	fren* rAlly[3];
	allyLoader() {};
	static allyLoader cally;
};

