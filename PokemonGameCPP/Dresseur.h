#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"

class Dresseur
{
private:
	std::string name;
	std::vector<Pokemon> team;

public:
	Dresseur(std::string name){}
	~Dresseur(){}
	std::string GetName();
	void AddPokemon(const Pokemon& pokemon);
	void ShowTeam();
};

