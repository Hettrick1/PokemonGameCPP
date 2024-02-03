#include "Abilities.h"

Abilities::Abilities(std::string aName, float aDamages, PokeType aType) {
	name = aName;
	damages = aDamages;
	type = aType;
}

Abilities::~Abilities(){}

float Abilities::GetDamages() {
	return damages;
}

PokeType Abilities::GetAbilityType() {
	return type;
}

std::string Abilities::GetAbilityName() {
	return name;
}