#include "Initialisation.h"
#include "Random.h"
#include "Abilities.h"
#include "Pokemon.h"
#include "PokemonData.h"

#include <vector>

Initialisation::Initialisation() {
    std::vector<std::string> names = GetAllPokemonNames();

    Dresseur dresseur = Dresseur("Ash", "alfn", "afkj", 100, 100, 10);

    for (int i = 0; i < 6; i++)
    {
        Pokemon newPokemon = NewPokemon(names);
        dresseur.AddPokemon(newPokemon);
    }

    AllDresseurs.push_back(dresseur);

    Abilities newAbility = Abilities("hello", 10, PokeType::ELECTRIC, 100);
    abilitiesAvailable.push_back(newAbility);
}
Initialisation::~Initialisation() {}

std::string Initialisation::ChooseName(std::vector<std::string>& Allnames) {
    Random random;
    int randomIndex = random.RangeInt(0, static_cast<int>(Allnames.size() - 1));
    return Allnames[randomIndex];
}


int Initialisation::ChooseInt(int min, int max) {
    Random random;
    int randomLevel = random.RangeInt(min, max);
    return randomLevel;
}

Pokemon Initialisation::NewPokemon(std::vector<std::string>& AllNames) {
    std::string name = ChooseName(AllNames);
    std::string description = GetPokemonDescription(name);
    PokeType type = GetPokemonType(name);
    int level = ChooseInt(1, 21);
    int health = ChooseInt(20, 51);

    return Pokemon(name, type, level, description, static_cast<float>(health));
}
Dresseur Initialisation::GetDresseur(int dresseurIndex) {
    return AllDresseurs[dresseurIndex];
}
std::vector<Abilities>& Initialisation::GetAbilitiesAvailable(){
    return abilitiesAvailable;
}