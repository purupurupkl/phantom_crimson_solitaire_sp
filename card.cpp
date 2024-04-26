#include "card.h"
card::card() {}
card::card(int a, int h) {
	atkmod = a;
	hpmod = h;		
	
}
card::~card(){}
void card::random(int hpcap, int atkcap) {
	hpmod = rand() % 20 + 1 + hpcap - 30;
	atkmod = rand() % 40 + 1 + atkcap - 40;
	text = "Your whole team gain " + std::to_string(atkmod) + " ATK and " + std::to_string(hpmod) + " hp";
}