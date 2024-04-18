#pragma once
#include "image.h"
class skill
{
public:
	skill(int, double,int, int);
	skill();
	skill operator=(const skill& other);
	int type;
	double multiplier;
	int cooldown;
	int cd;
	bool choosen;
};

namespace skillStats{
	const skill base(0, 1, 0, 0);
	const skill Zeta_s2(0, 1.2, 0, 12);
}