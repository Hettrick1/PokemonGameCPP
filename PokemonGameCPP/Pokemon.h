#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Poketype.h"
#include "Abilities.h"

class Pokemon
{
private:
	std::string name;
	PokeType type;
	int level;
	std::string description;
	int health;
	std::vector<Abilities> abilities;
	bool incapacited;
public:
	Pokemon(std::string name, PokeType type, int level, std::string description, int health);
	~Pokemon();
	std::string GetName() const;
	PokeType GetType();
	int GetLevel() const;
	std::string GetDescription() const;
	int GetHealth() const;
	bool GetIncapacited();
	int calculateDamage(Abilities& ability, Pokemon& defender);
	void TakeDamages(int damage);
};



