#include "Dresseur.h"
#include "Pokemon.h"

#include <iostream>

Dresseur::Dresseur() {
	name = "Player";
	lastName = "Player";
	catchPhrase = "CatchPhrase";
	money = 100;
	lifePoints = 100;
	pokeballs = 10;
}

Dresseur::Dresseur(std::string dName, std::string dLastName, std::string dCatchPhrase, int dMoney, int dLifePoints, int dPokeballs) {
	name = dName;
	lastName = dLastName;
	catchPhrase = dCatchPhrase;
	money = dMoney;
	lifePoints = dLifePoints;
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
void Dresseur::AddPokemon(const Pokemon& pokemon) {
	team.push_back(pokemon); 
}
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

void Dresseur::ChangeCurrentPokemon(){
	std::vector<Pokemon> pokemonsAvailable;
	pokemonsAvailable.clear();
	int answer = 0;
	for (Pokemon& pokemon : team) {
		if (!pokemon.GetIncapacited()) {
			pokemonsAvailable.push_back(pokemon);
		}
	}
	std::cout << "\nVous avez tous ces Pokemons de disponibles pour la bataille, lequel voulez vous choisir ?\n";
	size_t pokemonsAvailableSize = pokemonsAvailable.size();
	for (int i = 0; i < pokemonsAvailableSize; i++) {
		std::cout << i + 1 << ". " << pokemonsAvailable[i].GetName() << "\n";
	}
	do {
		std::cin >> answer;
	} while (answer <= 0 || answer > pokemonsAvailableSize);

	currentPokemon = pokemonsAvailable[answer - 1];
	std::cout << "Vous avez choisi : " << currentPokemon.GetName() << ".\n";
}

Pokemon& Dresseur::GetCurrentPokemon() {
	return currentPokemon;
}

int Dresseur::GetMoney() {
	return money;
}
Pokemon Dresseur::SetCurrentPokemon(Pokemon& pokemon) {
	currentPokemon = pokemon;
	return currentPokemon;
}