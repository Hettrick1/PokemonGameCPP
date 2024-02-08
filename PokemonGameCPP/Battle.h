#pragma once
#include "Dresseur.h"
#include "Pokemon.h"

class Battle
{
private:

public:
	Battle(Dresseur player, Dresseur opponent);
	Battle(Dresseur player, Pokemon wildPokemon);
	~Battle();
	void Fight(Dresseur& player, Dresseur& opponent);
};

