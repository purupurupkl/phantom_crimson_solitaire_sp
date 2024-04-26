#include "allyLoader.h"
allyLoader allyLoader::cally;
allyLoader& allyLoader::get() {
	return cally;
}
void allyLoader::realfren(fren* ally[3]) {
	for (int i = 0; i < 3; i++) {
		ally[i] = rAlly[i];
	}
}
void allyLoader::initAlly() {
	for (int i = 0; i < 3; i++) {
		rAlly[i] = new fren(i+1);
	}
}
void allyLoader::applyCard(int atkmod, int hpmod) {
	for (int i = 0; i < 3; i++) {
		rAlly[i]->stats.maxhp += hpmod;
		rAlly[i]->stats.hp += hpmod;
		rAlly[i]->stats.atk += atkmod;
		rAlly[i]->stats.maxatk += atkmod;
	}
}
void allyLoader::reset(){
	for (int i = 0; i < 3; i++) {
		delete rAlly[i];
		rAlly[i] = NULL;
	}
	allyLoader::initAlly();
}
