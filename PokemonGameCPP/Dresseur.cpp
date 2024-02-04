#include "Pokemon.h"
#include "Dresseur.h"

#include <iostream>

Dresseur::Dresseur(std::string dName, std::string dLastName, std::string dCatchPhrase, int dMoney, int dLifePoints, int dPokeballs) {
	name = dName;
	lastName = dLastName;
	catchPhrase = dCatchPhrase;
	money = dMoney;
	lifePoints = dLifePoints; // ca me sert a rien ce machin là en fait
	pokeballs = dPokeballs;
}
Dresseur::Dresseur(std::string dName, std::string dLastName, std::string dCatchPhrase) {
	name = dName;
	lastName = dLastName;
	catchPhrase = dCatchPhrase;
	money = 100;
	lifePoints = 100;
	pokeballs = 10;
}
Dresseur::~Dresseur() {}
std::string Dresseur::GetName() { return name; }
void Dresseur::AddPokemon(const Pokemon& pokemon) { team.push_back(pokemon); }
std::vector<Pokemon> Dresseur::GetTeam() { return team; }
void Dresseur::ShowTeam() {
	std::cout << "Dresseur : " << name << "\nTeam : \n";
	for (const Pokemon& pokemon : team) {
		std::cout << pokemon.GetName() << " " << pokemon.GetLevel() << "\nDescription : " << pokemon.GetDescription() << "\n";
	}
}
void Dresseur::Introduce() {
	std::cout << "Bonjour, mon nom est " << name << " " << lastName << ".\n" << catchPhrase << "\n";
}

void Dresseur::UsePokemonAbility(Pokemon& attackingPokemon, Pokemon& targetPokemon, Abilities& ability) {
	//faire des dégats au targetPokemon
}
void Dresseur::EarnMoney(int amount) {
	money += amount;
	std::cout << "Earned " << amount << " money. Total money: " << money << "\n";
}

void Dresseur::EarnPokeballs(int count) {
	pokeballs += count;
	std::cout << "Earned " << count << " pokeballs. Total pokeballs: " << pokeballs << "\n";
}

void Dresseur::ChangeCurrentPokemon(int i){
	//afpmaf

}
