#include <iostream>
#include <vector>
#include <random>

#include "Dresseur.h"
#include "Pokemon.h"
#include "Random.h"
#include "PokemonData.h"
#include "Battle.h"
#include "Initialisation.h"


int main()
{    
    Initialisation init = Initialisation();

    init.GetPlayer().ChangeCurrentPokemon();

    init.GetPlayer().GetCurrentPokemon().LearnAbilities(init.GetAbilitiesAvailable());

    Battle battle = Battle(init.GetPlayer(), init.GetDresseur(0));
    do {
        battle.Fight(init.GetPlayer(), init.GetDresseur(0));
        for (Pokemon pokemons : init.GetDresseur(0).GetTeam()) {

        }
    } while (init.GetDresseur(0).GetTeam()[init.GetDresseur(0).GetTeam().size()].GetIncapacited());
    

    return 0;
}

