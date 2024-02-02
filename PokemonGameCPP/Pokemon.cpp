#include "Pokemon.h"

Pokemon::Pokemon(std::string pName, int pLevel, std::string pDescription, int pHealth, std::string pType) {
	name = pName;
	level = pLevel;
	description = pDescription;
	health = pHealth;
	type = pType;
}
Pokemon::~Pokemon() {}

std::string Pokemon::GetName() const { return name; }
int Pokemon::GetLevel() const { return level; }
std::string Pokemon::GetDescription() const { return description; }
int Pokemon::GetHealth() const { return health; }
std::string Pokemon::GetType() const { return type; }