#pragma once

#include <iostream>
#include <string>

#include "Poketype.h"

class Abilities
{
private:
	std::string name;
	float damages;
	PokeType type;


public:
	Abilities(std::string name, float damages, PokeType type);
	~Abilities();
	float GetDamages();
	PokeType GetAbilityType();
	std::string GetAbilityName();
};

