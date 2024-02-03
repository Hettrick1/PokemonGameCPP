#pragma once

#include <iostream>
#include <string>

#include "Poketype.h"

class Abilities
{
private:
	std::string name;
	int damages;
	PokeType type;

public:
	Abilities(std::string name, int damages, PokeType type);
	~Abilities();
	int GetDamages();
	PokeType GetAbilityType();
	std::string GetAbilityName();
};

