#pragma once
#include <unordered_map>
#include <SDL_mixer.h>
#include <string>
class skill
{
public:
	skill(int, double, int, std::string);
	skill();
	skill operator=(const skill& other);
	int type;
	double multiplier;
	int cooldown; // cooldown for calculation	
	int cd; // real cooldown
	bool choosen;
	std::string s_path;
	Mix_Chunk* sfx;
	//int use();
};
namespace skillStats{
	const skill base(0, 1, 0, "resources\\sfx\\base.wav");
	const skill April_s2(0, 1.2, 3, "resources\\sfx\\april_sfx1.mp3");
	const skill Saga_s2(0, 1.1, 1, "resources\\sfx\\saga_sfx1.mp3");
	const skill Nian_s2(1, 1.2, 2, "resources\\sfx\\nian_sfx_s2.mp3");
	const skill dawg(0, 1.5, 10, "resources\\sfx\\base.wav");
	const skill soldier(0, 1.2, 3, "resources\\sfx\\base.wav");
	const skill lock(0, 1.5, 5, "resources\\sfx\\chain.mp3");
	const std::unordered_map<int, std::pair<skill, skill>> skillset{
		{1, std::make_pair(base, Nian_s2)},
		{2, std::make_pair(base, Saga_s2)},
		{3, std::make_pair(base, April_s2)},
		{-1, std::make_pair(base, dawg)},
		{-2, std::make_pair(base, soldier)},
		{0, std::make_pair(base, lock)}
	};
}
