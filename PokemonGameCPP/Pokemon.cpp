#include "Pokemon.h"

Pokemon::Pokemon(std::string pName, std::map<std::string, PokeType> pInfo, int pLevel, std::string pDescription, int pHealth) {
	name = pName;
	level = pLevel;
	description = pDescription;
	health = pHealth;

}
Pokemon::~Pokemon() {}

std::string Pokemon::GetName() const { return name; }
int Pokemon::GetLevel() const { return level; }
std::string Pokemon::GetDescription() const { return description; }
int Pokemon::GetHealth() const { return health; }
PokeType Pokemon::GetType() { return pokemonInfo[name];}