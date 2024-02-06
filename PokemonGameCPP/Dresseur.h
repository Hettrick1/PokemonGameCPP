#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Abilities.h"
#include "Pokemon.h"

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
	Pokemon currentPokemon;

public:
	Dresseur();
	Dresseur(std::string dName, std::string dLastName, std::string dCatchPhrase, int dMoney, int dLifePoints, int dPokeballs);
	Dresseur(std::string dName, std::string dLastName, std::string dCatchPhrase);
	~Dresseur();
	std::string GetName();
	std::vector<Pokemon> GetTeam();
	void AddPokemon(const Pokemon& pokemon);
	void ShowTeam();
	void Introduce();
	void UsePokemonAbility(Pokemon& attackingPokemon, Pokemon& targetPokemon, Abilities& ability);
	void EarnMoney(int amount);
	void EarnPokeballs(int count);
	void ChangeCurrentPokemon();
	Pokemon GetCurrentPokemon();
	int GetMoney();
	Pokemon SetCurrentPokemon(Pokemon& pokemon);
};


