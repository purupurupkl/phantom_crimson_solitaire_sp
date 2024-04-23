#pragma once
#include <string>
class card
{
public:
	card();
	card(int, int );
	~card();
	int atkmod;
	int hpmod;
	std::string text;
	void random(int hpcap,int atkcap);
	//for now this will do
};



