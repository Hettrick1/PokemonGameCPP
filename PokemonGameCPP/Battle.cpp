#include "Battle.h"
#include "Pokemon.h"
#include "Dresseur.h"

Battle::Battle(Dresseur player, Dresseur opponent) {
	std::cout << "Vous commencez un combat contre : " << opponent.GetName() << "\n";
	opponent.Introduce();
	player.Introduce();
	opponent.GetCurrentPokemon().GoOutOfPokeball();
	player.ChangeCurrentPokemon();
}
Battle::Battle(Dresseur player, Pokemon wildPokemon) {

}
Battle::~Battle(){}

void Battle::Fight(Dresseur& player, Dresseur& opponent) {
	player.GetCurrentPokemon().ChoseAbilities(player.GetCurrentPokemon().GetAbilities(), opponent.GetCurrentPokemon());
}
