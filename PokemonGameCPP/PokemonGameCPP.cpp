#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "Dresseur.h"
#include "Pokemon.h"

Pokemon NewPokemon(const std::vector<std::string>& names, const std::vector<std::string>& descriptions, const std::vector<std::string>& types, std::mt19937& gen);
std::string ChooseName(const std::vector<std::string>& names, std::mt19937& gen);
int ChooseLevel(std::mt19937& gen);
int ChooseHealth(std::mt19937& gen);

int main()
{
    std::vector<std::string> pokemonNames = { "Bulbizarre", "Pikachu", "Salameche" };
    std::vector<std::string> pokemonDescr = { "Bulbizarre est une créature courtaude et vaguement reptilienne qui se déplace à quatre pattes et possède un corps bleu-vert clair avec des taches bleu-vert plus foncées.",
    "Décrit comme une souris, Pikachu évoque un petit rongeur d'une quarantaine de centimètres pour six kilogrammes, avec un corps rond, de courtes pattes et une queue aussi longue que son corps.",
    "La flamme qui brûle au bout de sa queue indique l'humeur de ce Pokémon. Elle vacille lorsque Salamèche est content." };
    std::vector<std::string> pokemonTypes = { "Herbe", "Electricite", "Feu" };

    std::random_device rd;
    std::mt19937 gen(rd());

    Dresseur ash = Dresseur("Ash");

    for (int i = 0; i < 3; i++)
    {
        Pokemon newPokemon = NewPokemon(pokemonNames, pokemonDescr, pokemonTypes, gen);
        ash.AddPokemon(newPokemon);
    }

    ash.ShowTeam();

    return 0;
}

std::string ChooseName(const std::vector<std::string>& names, std::mt19937& gen) {

    std::uniform_int_distribution<std::size_t> dist(0, names.size() - 1);

    std::size_t randomIndex = dist(gen);
    return names[randomIndex];
}

int ChooseLevel(std::mt19937& gen) {

    std::uniform_int_distribution<int> dist(1, 21);
    int randomLevel = dist(gen);
    return randomLevel;
}

int ChooseHealth(std::mt19937& gen) {
    ;
    std::uniform_int_distribution<int> dist(50, 101);
    int randomHps = dist(gen);
    return randomHps;
}

Pokemon NewPokemon(const std::vector<std::string>& names, const std::vector<std::string>& descriptions, const std::vector<std::string>& types, std::mt19937& gen) {
    std::string name = ChooseName(names, gen);
    std::string description;
    std::string type;
    for (int i = 0; i < names.size(); i++) {
        if (name == names[i]) 
        {
            description = descriptions[i];
            type = types[i];
        }
    }
    int level = ChooseLevel(gen);
    int health = ChooseHealth(gen);

    return Pokemon(name, level, description, health, type);
}
