#pragma once

#include <iostream>
#include <map>
#include <string>
#include "Poketype.h"

class Pokemon
{
private:
	std::string name;
	std::map<std::string, PokeType> pokemonInfo;
	int level;
	std::string description;
	int health;
	std::string type;
public:
	Pokemon(std::string name, std::map<std::string, PokeType> pokemonInfo, int level, std::string description, int health);
	~Pokemon();
	std::string GetName() const;
	PokeType GetType();
	int GetLevel() const;
	std::string GetDescription() const;
	int GetHealth() const;
};



