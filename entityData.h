#pragma once
#include <string>
struct entityData {
	entityData() {};
	entityData(std::string name, double hp, double atk);
	entityData operator=(const entityData& other);
	std::string name;
	double hp;
	double atk;
};


namespace characterStats{
	const entityData DjeetaStats = { "Djeeta", 900, 50};
	const entityData CagliostroStats = { "Cagliostro", 50, 90};
	const entityData ZetaStats = { "Zeta", 80, 60};
	const entityData DogStats = { "Dog", 200, 100};
}

