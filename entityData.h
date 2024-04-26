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
	const entityData NianStats("Nian", 500, 30, 60);
	const entityData SagaStats("Saga", 300, 50, 40);
	const entityData AprilStats("April", 200, 90, 10);
	const entityData DogStats("Dog", 90, 30, 10);
	const entityData SolStats("Reunion Soldier", 150, 50, 20);
	const entityData LockStats("Big Sad Lock", 800, 60, 50);
	const std::unordered_map<int, entityData> characterData = {
		{1, NianStats},
		{2,SagaStats},
		{3,AprilStats},
		{-1,DogStats},
		{-2,SolStats},
		{0, LockStats}
	};
}

