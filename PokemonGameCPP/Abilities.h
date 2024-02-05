#pragma once

#include <iostream>
#include <string>

#include "Poketype.h"

class Abilities
{
private:
	std::string name;
	float damages;
	int maxUses;
	int currentUses;
	PokeType type;
	int price;

public:
	Abilities(std::string name, float damages, PokeType type, int aPrice);
	~Abilities();
	float GetDamages();
	PokeType GetAbilityType();
	std::string GetAbilityName();
	bool CanUse();
	void ResetUses();
	void SetCurrentUses();
	int GetPrice();
};

