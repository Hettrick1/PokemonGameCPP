#include "Pokemon.h"
#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur(std::string dName) {
	name = dName;
}
Dresseur::~Dresseur() {}
std::string Dresseur::GetName() { return name; }
void Dresseur::AddPokemon(const Pokemon& pokemon) { team.push_back(pokemon); }
void Dresseur::ShowTeam() {
	std::cout << "Dresseur : " << name << "\nTeam : \n";
	for (const Pokemon& pokemon : team) {
		std::cout << pokemon.GetName() << " " << pokemon.GetLevel() <<"\n";
	}
}
