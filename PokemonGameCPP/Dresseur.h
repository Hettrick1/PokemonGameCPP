#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Abilities.h"

class Pokemon;

class Dresseur
{
private:
	std::string name;
	std::string lastName;
	std::string catchPhrase;
	int money;
	int lifePoints;
	int pokeballs;
	std::vector<Pokemon> team;

public:
	Dresseur(std::string dName, std::string dLastName, std::string dCatchPhrase, int dMoney, int dLifePoints, int dPokeballs);
	~Dresseur();
	std::string GetName();
	void AddPokemon(const Pokemon& pokemon);
	void ShowTeam();
	void Introduce();
	void UsePokemonAbility(Pokemon& attackingPokemon, Pokemon& targetPokemon, Abilities& ability);
	void earnMoney(int amount);
	void earnPokeballs(int count);
};


