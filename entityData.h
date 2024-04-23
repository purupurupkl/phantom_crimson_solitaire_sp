#pragma once
#include <string>
#include <unordered_map>
struct entityData {
	entityData() {};
	entityData(std::string name, int health, int attack, int defense);
	entityData operator=(const entityData& other);
	std::string name;
	int maxhp;  int hp;
	int maxatk; int atk;
	int maxdef; int def; 
};


namespace characterStats{
	const entityData NianStats("Nian", 300, 50, 20);
	const entityData SagaStats("Saga", 700, 90, 20);
	const entityData AprilStats("April", 80, 60, 20);
	const entityData DogStats("Dog", 100, 50, 10);
	const std::unordered_map<int, entityData> characterData = {
		{1, NianStats},
		{2,SagaStats},
		{3,AprilStats},
		{-1,DogStats}
	};
}

