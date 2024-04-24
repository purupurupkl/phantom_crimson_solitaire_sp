#pragma once
#include <unordered_map>
class skill
{
public:
	skill(int, double, int);
	skill();
	skill operator=(const skill& other);
	int type;
	double multiplier;
	int cooldown; // cooldown for calculation
	int cd; // real cooldown
	bool choosen;
};
namespace skillStats{
	const skill base(0, 1, 0);
	const skill April_s2(0, 1.2, 3);
	const skill Saga_s2(0, 1.1, 1);
	const skill Nian_s2(1, 1.2, 2);
	const skill dawg(0, 1.5, 10);
	const skill soldier(0, 1.2, 3);
	const std::unordered_map<int, std::pair<skill, skill>> skillset{
		{1, std::make_pair(base, Nian_s2)},
		{2, std::make_pair(base, Saga_s2)},
		{3, std::make_pair(base, April_s2)},
		{-1, std::make_pair(base, dawg)},
		{-2, std::make_pair(base, soldier)}
	};
}
