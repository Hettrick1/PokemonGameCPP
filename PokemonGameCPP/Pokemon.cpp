#include "Pokemon.h"
#include "Abilities.h"
#include "PokemonData.h"

Pokemon::Pokemon(std::string pName, PokeType pType, int pLevel, std::string pDescription, int pHealth) {
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
int Pokemon::GetHealth() const { return health; }
PokeType Pokemon::GetType() { return type;}
bool Pokemon::GetIncapacited() { return incapacited; }

int Pokemon::calculateDamage(Abilities& ability, Pokemon& defender) {

	PokeType attackType = ability.GetAbilityType();
	std::cout << static_cast<int>(attackType);

	PokeType defenderType = defender.GetType();
	std::cout << static_cast<int>(defenderType);
	
	float resistance = GetResistance(static_cast<int>(attackType), static_cast<int>(defenderType));

	int damage = static_cast<int>(ability.GetDamages() * resistance);

	return damage;
}

void Pokemon::TakeDamages(int damages) {
	if (health > damages) {
		health = 0;
	}
	else {
		incapacited = true;
	}
}