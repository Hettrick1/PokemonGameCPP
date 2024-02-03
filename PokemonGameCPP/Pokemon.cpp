#include "Pokemon.h"

Pokemon::Pokemon(std::string pName, PokeType pType, int pLevel, std::string pDescription, int pHealth) {
	name = pName;
	type = pType;
	level = pLevel;
	description = pDescription;
	health = pHealth;

}
Pokemon::~Pokemon() {}

std::string Pokemon::GetName() const { return name; }
int Pokemon::GetLevel() const { return level; }
std::string Pokemon::GetDescription() const { return description; }
int Pokemon::GetHealth() const { return health; }
PokeType Pokemon::GetType() { return type;}