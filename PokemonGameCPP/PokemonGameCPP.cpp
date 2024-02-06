#include <iostream>
#include <vector>
#include <random>

#include "Dresseur.h"
#include "Pokemon.h"
#include "Random.h"
#include "PokemonData.h"
#include "Initialisation.h"


int main()
{    
    Initialisation init = Initialisation();

    std::cout << init.GetDresseur(0).GetTeam()[1].GetName() << "\n";
    
    std::cout << "dégats : " << init.GetDresseur(0).GetTeam()[0].CalculateDamage(init.GetAbilitiesAvailable()[0], init.GetDresseur(0).GetTeam()[1]);

    init.GetPlayer().ChangeCurrentPokemon();

    init.GetPlayer().GetCurrentPokemon().LearnAbilities(init.GetAbilitiesAvailable());

    return 0;
}

