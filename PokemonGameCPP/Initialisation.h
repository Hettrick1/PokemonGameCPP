#pragma once
#include "Abilities.h"
#include "Dresseur.h"
#include "Pokemon.h"

#include <vector>

class Initialisation
{
private:
	std::vector<Dresseur> AllDresseurs;
	Dresseur player;
	std::vector<Abilities> abilitiesAvailable;
public:
	Initialisation();
	~Initialisation();
	std::string ChooseName(std::vector<std::string>& Allnames);
	int ChooseInt(int min, int max);
	Pokemon NewPokemon(std::vector<std::string>& AllNames);
	Dresseur& GetDresseur(int dresseurIndex);
	std::vector<Abilities>& GetAbilitiesAvailable();
	void CreatePlayer();
	Dresseur& GetPlayer();
};

