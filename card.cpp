#include "card.h"
card::card() {}
card::card(int a, int h) {
	atkmod = a;
	hpmod = h;		
	
}
card::~card(){}
void card::random(int hpcap, int atkcap) {
	hpmod = rand() % hpcap +1;
	atkmod = rand() % atkcap + 1;
	text = "Your whole team gain " + std::to_string(atkmod) + " ATK and " + std::to_string(hpmod) + " hp";
}