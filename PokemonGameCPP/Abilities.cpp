#include "Abilities.h"

Abilities::Abilities(std::string aName, int aDamages, PokeType aType) {
	name = aName;
	damages = aDamages;
	type = aType;
}

Abilities::~Abilities(){}

int Abilities::GetDamages() {
	return damages;
}

PokeType Abilities::GetAbilityType() {
	return type;
}

std::string Abilities::GetAbilityName() {
	return name;
}