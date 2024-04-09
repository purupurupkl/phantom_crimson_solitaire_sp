#pragma once
#include <string>
#include <map>	
struct skill {
	/*enum skilltype {
		attack,
		defense,
		support
	};*/
	//string name
	/*int type;*/
	double multiplier;
};
struct entityData {
	std::string name;
	double hp;
	double atk;
	skill s1, s2;
};

namespace characterStats {
	const entityData DjeetaStats = { "Djeeta", 100, 50, skillStats::base, skillStats::Zeta_s2 };
	const entityData CagliostroStats = { "Cagliostro", 50, 90, skillStats::base, skillStats::Zeta_s2 };
	const entityData ZetaStats = { "Zeta", 80, 60, skillStats::base, skillStats::Zeta_s2 };



	const entityData DogStats = { "Dog", 70, 10 };

	//enum names {
	//	Djeeta, Cagliostro,Zeta
	//};
	//std::map<names, entityData> entities;
	//entities[Djeeta] = 
}
namespace skillStats {
	const skill base{ 1 };
	const skill Zeta_s2{ 1.2 };
}