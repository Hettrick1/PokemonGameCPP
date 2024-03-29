#pragma once
#include "Dresseur.h"
#include "Pokemon.h"

class Battle
{
private:
	bool stopBattle;
	bool enemyDefeated;
public:
	Battle(Dresseur& player, Dresseur& opponent);
	Battle(Dresseur& player, Pokemon& wildPokemon);
	~Battle();
	void Fight(Dresseur& player, Dresseur& opponent);
	void Quit();
	bool GetQuit();
	bool GetDefeated();
};

