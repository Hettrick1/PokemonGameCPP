#include "Pokemon.h"

Pokemon::Pokemon(std::string pName, int pLevel, std::string pDescription, int pHealth, std::string pType) {
	name = pName;
	level = pLevel;
	description = pDescription;
	health = pHealth;
	type = pType;
}
Pokemon::~Pokemon(){}

std::string Pokemon::GetName() { return name; }
int Pokemon::GetLevel() { return level; }
std::string Pokemon::GetDescription() { return description; }
int Pokemon::GetHealth() { return health; }
std::string Pokemon::GetType() { return type; }