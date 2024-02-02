#include <iostream>
#include <vector>
#include <random>

#include "Dresseur.h"
#include "Pokemon.h"
#include "Random.h"

Pokemon NewPokemon(std::map<std::string, std::string>& namesAndTypes, const std::vector<std::string>& descriptions);
std::string ChooseName(std::map<std::string, std::string>& namesAndTypes);
int ChooseInt(int mint, int max);

int main()
{
    std::map<std::string, std::string> namesAndTypes = {
    { "Bulbizarre", "Herbe" },
    { "Pikachu", "Electricite" },
    { "Salameche", "Feu" } };
    std::vector<std::string> pokemonDescr = { "Bulbizarre est une créature courtaude et vaguement reptilienne qui se déplace à quatre pattes et possède un corps bleu-vert clair avec des taches bleu-vert plus foncées.",
    "Décrit comme une souris, Pikachu évoque un petit rongeur d'une quarantaine de centimètres pour six kilogrammes, avec un corps rond, de courtes pattes et une queue aussi longue que son corps.",
    "La flamme qui brûle au bout de sa queue indique l'humeur de ce Pokémon. Elle vacille lorsque Salamèche est content." };

    Dresseur ash = Dresseur("Ash");

    for (int i = 0; i < 3; i++)
    {
        Pokemon newPokemon = NewPokemon(namesAndTypes, pokemonDescr);
        ash.AddPokemon(newPokemon);
    }

    ash.ShowTeam();

    return 0;
}

std::string ChooseName(std::map<std::string, std::string>& namesAndTypes) {
    Random random;
    int randomIndex = random.RangeInt(0, static_cast<int>(namesAndTypes.size() - 1));
    return " ";
}


int ChooseInt(int min, int max) {
    Random random;
    int randomLevel = random.RangeInt(min, max);
    return randomLevel;
}

Pokemon NewPokemon(std::map<std::string, std::string>& namesAndTypes, const std::vector<std::string>& descriptions) {
    std::string name = ChooseName(namesAndTypes);
    std::string description;
    std::string type;
    std::map<std::string, PokeType> nameAndType;

    type = namesAndTypes[name];

    int level = ChooseInt(1, 21);
    int health = ChooseInt(20, 51);

    return Pokemon(name, nameAndType, level, description, health);
}
