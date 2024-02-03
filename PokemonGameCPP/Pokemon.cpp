#include "Pokemon.h"
#include "Abilities.h"
#include "PokemonData.h"

Pokemon::Pokemon(std::string pName, PokeType pType, int pLevel, std::string pDescription, float pHealth) {
	name = pName;
	type = pType;
	level = pLevel;
	description = pDescription;
	health = pHealth;
	incapacited = false;
}
Pokemon::~Pokemon() {}

std::string Pokemon::GetName() const { return name; }
int Pokemon::GetLevel() const { return level; }
std::string Pokemon::GetDescription() const { return description; }
float Pokemon::GetHealth() const { return health; }
PokeType Pokemon::GetType() { return type;}
bool Pokemon::GetIncapacited() { return incapacited; }

float Pokemon::calculateDamage(Abilities& ability, Pokemon& defender) {

	PokeType attackType = ability.GetAbilityType();

	PokeType defenderType = defender.GetType();
	
	float resistance = GetResistance(static_cast<int>(attackType), static_cast<int>(defenderType));

	float damage = ability.GetDamages() * resistance;

	return damage;
}

void Pokemon::TakeDamages(float damages) {
	if (health > damages) {
		health = 0;
	}
	else {
		incapacited = true;
	}
}