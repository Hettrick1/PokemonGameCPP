#include "Abilities.h"

Abilities::Abilities(std::string aName, float aDamages, PokeType aType, int aPrice) {
	name = aName;
	damages = aDamages;
	type = aType;
	maxUses = 5;
	currentUses = 0;
	price = aPrice;
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

bool Abilities::CanUse() {
	return currentUses < maxUses;
}
void Abilities::ResetUses() {
	currentUses = 0;
}
void Abilities::SetCurrentUses() {
	currentUses++;
}

int Abilities::GetPrice() {
	return price;
}