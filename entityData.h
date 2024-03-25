#pragma once
#include <string>
#include <map>	
struct entityData {
	std::string name;
	int hp;
	int atk;
};

namespace characterStats {
	const entityData DjeetaStats = { "Djeeta", 100, 50 };
	const entityData CagliostroStats = { "Cagliostro", 50, 90 };
	const entityData ZetaStats = { "Zeta", 80, 60 };



	const entityData DogStats = { "Dog", 70, 10 };

	//enum names {
	//	Djeeta, Cagliostro,Zeta
	//};
	//std::map<names, entityData> entities;
	//entities[Djeeta] = 
}
