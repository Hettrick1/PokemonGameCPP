#include <iostream>
#include <vector>
#include <random>

#include "Dresseur.h"
#include "Pokemon.h"
#include "Random.h"
#include "PokemonData.h"

Pokemon NewPokemon(std::vector<std::string>& Allnames);
std::string ChooseName(std::vector<std::string>& Allnames);
int ChooseInt(int mint, int max);

int main()
{
    std::vector<std::string> names = GetAllPokemonNames();

    Dresseur ash = Dresseur("Ash", "alfn", "afkj", 100, 100, 10);

    for (int i = 0; i < 6; i++)
    {
        Pokemon newPokemon = NewPokemon(names);
        ash.AddPokemon(newPokemon);
    }

    Abilities a1 = Abilities("hello", 10, PokeType::ELECTRIC);

    std::cout << ash.GetTeam()[1].GetName() << "\n";
    
    std::cout << "degats : " << ash.GetTeam()[0].calculateDamage(a1, ash.GetTeam()[1]);

    ash.ChangeCurrentPokemon();
    ash.ChangeCurrentPokemon();

    return 0;
}

std::string ChooseName(std::vector<std::string>& Allnames) {
    Random random;
    int randomIndex = random.RangeInt(0, static_cast<int>(Allnames.size() - 1));
    return Allnames[randomIndex];
}


int ChooseInt(int min, int max) {
    Random random;
    int randomLevel = random.RangeInt(min, max);
    return randomLevel;
}

Pokemon NewPokemon(std::vector<std::string>& AllNames) {
    std::string name = ChooseName(AllNames);
    std::string description = GetPokemonDescription(name);
    PokeType type = GetPokemonType(name);
    int level = ChooseInt(1, 21);
    int health = ChooseInt(20, 51);

    return Pokemon(name, type, level, description, health);
}
