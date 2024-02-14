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
	enemyDefeated = false;
}
Battle::Battle(Dresseur& player, Pokemon& wildPokemon) {
	stopBattle = false;
	enemyDefeated = false;
}
Battle::~Battle(){ 
	stopBattle = false; 
	enemyDefeated = false;}

void Battle::Fight(Dresseur& player, Dresseur& opponent) {
	int index = 0;
	int answer;
	do {
		std::cout << "\nQue voulez-vous faire ?\n1. Changer de pokemon\n2. Choisir un abilite pour attaquer\n3. Fuir le combat\n";
		std::cin >> answer;
	} while (answer <= 0 || answer > 3); 
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
	if (opponent.GetCurrentPokemon()->GetIncapacited()) {
		index++;
		std::cout << "Le pokemon adverse est assome.\n";
		if (index < opponent.GetTeam().size()) {
			opponent.SetCurrentPokemon(index);
		}
		else
		{
			enemyDefeated = true;
		}
	}
	else
	{
		std::cout << "Il reste " << opponent.GetCurrentPokemon()->GetHealth() << " pvs au pokemon adverse.\n";
	}
}

void Battle::Quit() {
	stopBattle = true;
}

bool Battle::GetQuit() {
	return stopBattle;
}

bool Battle::GetDefeated()
{
	return enemyDefeated;
}
