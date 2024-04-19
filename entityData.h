#pragma once
#include <string>
struct entityData {
	entityData() {};
	entityData(std::string name, int health, int attack);
	entityData operator=(const entityData& other);
	std::string name;
	int maxhp;
	int hp;
	int maxatk;
	int atk;
};


namespace characterStats{
	const entityData KkrStats("Djeeta", 900, 50);
	const entityData CagliostroStats("Cagliostro", 50, 90);
	const entityData ZetaStats("Zeta", 80, 60);
	const entityData DogStats("Dog", 100, 50);
}

