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
		rAlly[i] = new fren(1);
	}
}
void allyLoader::allUpdate() {
	for (int i = 0; i < 3; i++) {
		rAlly[i]->statusUpdate();
	}
}
