#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "Dresseur.h"
#include "Pokemon.h"
#include "Random.h"

Pokemon NewPokemon(const std::vector<std::string>& names, const std::vector<std::string>& descriptions, const std::vector<std::string>& types, std::mt19937& gen);
std::string ChooseName(const std::vector<std::string>& names, std::mt19937& gen);
int ChooseInt(std::mt19937& gen, int mint, int max);

int main()
{
    std::vector<std::string> pokemonNames = { "Bulbizarre", "Pikachu", "Salameche" };
    std::vector<std::string> pokemonDescr = { "Bulbizarre est une créature courtaude et vaguement reptilienne qui se déplace à quatre pattes et possède un corps bleu-vert clair avec des taches bleu-vert plus foncées.",
    "Décrit comme une souris, Pikachu évoque un petit rongeur d'une quarantaine de centimètres pour six kilogrammes, avec un corps rond, de courtes pattes et une queue aussi longue que son corps.",
    "La flamme qui brûle au bout de sa queue indique l'humeur de ce Pokémon. Elle vacille lorsque Salamèche est content." };
    std::vector<std::string> pokemonTypes = { "Herbe", "Electricite", "Feu" };

    Dresseur ash = Dresseur("Ash");

    for (int i = 0; i < 3; i++)
    {
        Pokemon newPokemon = NewPokemon(pokemonNames, pokemonDescr, pokemonTypes);
        ash.AddPokemon(newPokemon);
    }

    ash.ShowTeam();

    return 0;
}

std::string ChooseName(const std::vector<std::string>& names) {
    std::size_t randomIndex = Random::RangeSizeT(0, names.size() - 1);
    return names[randomIndex];
}

int ChooseInt(int min, int max) {
    int randomLevel = Random::RangeInt(min, max);
    return randomLevel;
}

Pokemon NewPokemon(const std::vector<std::string>& names, const std::vector<std::string>& descriptions, const std::vector<std::string>& types) {
    std::string name = ChooseName(names);
    std::string description;
    std::string type;
    for (int i = 0; i < names.size(); i++) {
        if (name == names[i]) 
        {
            description = descriptions[i];
            type = types[i];
        }
    }
    int level = ChooseInt(1, 21);
    int health = ChooseInt(20, 51);

    return Pokemon(name, level, description, health, type);
}
