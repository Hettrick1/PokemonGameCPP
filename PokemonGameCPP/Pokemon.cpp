#include "Pokemon.h"
#include "Abilities.h"
#include "PokemonData.h"


Pokemon::Pokemon() {
	name = "Salamèche";
	type = PokeType::FIRE;
	description = "La flamme sur sa queue represente l energie vitale de Salameche. Quand il est vigoureux, elle brule plus fort.";
	health = 100;
	incapacited = false;
}
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

float Pokemon::CalculateDamage(Abilities& ability, Pokemon& defender) {

	if (ability.CanUse()) {
		ability.SetCurrentUses();
		PokeType attackType = ability.GetAbilityType();

		PokeType defenderType = defender.GetType();

		float resistance = GetResistance(static_cast<int>(attackType), static_cast<int>(defenderType));

		float damage = ability.GetDamages() * resistance;

		return damage;
	}
	else {
		std::cout << "la capacité " << ability.GetAbilityName() << " ne peut plus être utilisée. \n";
	}
}

void Pokemon::TakeDamages(float damages) {
	if (health > damages) {
		health = 0;
	}
	else {
		incapacited = true;
	}
}

void Pokemon::LearnAbilities(std::vector<Abilities>& abilitiesAvailable) {
	for (int i = 0; i < abilitiesAvailable.size(); i++) {
		std::cout << i + 1 << ". " << abilitiesAvailable[i].GetAbilityName() << " - " << abilitiesAvailable[i].GetPrice() << " pièces.\n";
	}
}