#include "Battle.h"
#include "Pokemon.h"
#include "Dresseur.h"

Battle::Battle(Dresseur& player, Dresseur& opponent) {
	std::cout << "Vous commencez un combat contre : " << opponent.GetName() << "\n";
	opponent.Introduce();
	player.Introduce();
	opponent.SetCurrentPokemon(0);
	opponent.GetCurrentPokemon()->GoOutOfPokeball();
	stopBattle = false;
}
Battle::Battle(Dresseur& player, Pokemon& wildPokemon) {
}
Battle::~Battle(){}

void Battle::Fight(Dresseur& player, Dresseur& opponent) {
	int answer;
	do {
		std::cout << "\nQue voulez-vous faire ?\n1. Changer de pokemon\n2. Choisir un abilite pour attaquer\n3. Fuir le combat\n";
		std::cin >> answer;
	} while (answer <= 0 || answer > 3);
	Pokemon* temp;
	switch (answer)
	{
	case 1:
		player.ChangeCurrentPokemon();
		break;
	case 2:
		std::cout << player.GetCurrentPokemon()->GetAbilities().size();
		player.GetCurrentPokemon()->ChoseAbilities(player.GetCurrentPokemon()->GetAbilities(), *(opponent.GetCurrentPokemon()));
		break;
	case 3:
		Quit();
		break;
	default:
		break;
	}	
}

void Battle::Quit() {
	stopBattle = true;
}

bool Battle::GetQuit() {
	return stopBattle;
}