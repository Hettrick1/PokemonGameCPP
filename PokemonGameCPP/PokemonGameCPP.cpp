#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "Dresseur.h"
#include "Pokemon.h"

Pokemon NewPokemon(const std::vector<std::string>& names, const std::vector<std::string>& descriptions, const std::vector<std::string>& types, std::mt19937& gen);
std::string ChooseName(const std::vector<std::string>& names, std::mt19937& gen);
int ChooseInt(std::mt19937& gen, int mint, int max);

int main()
{
    std::vector<std::string> pokemonNames = { "Bulbizarre", "Pikachu", "Salameche" };
    std::vector<std::string> pokemonDescr = { "Bulbizarre est une cr�ature courtaude et vaguement reptilienne qui se d�place � quatre pattes et poss�de un corps bleu-vert clair avec des taches bleu-vert plus fonc�es.",
    "D�crit comme une souris, Pikachu �voque un petit rongeur d'une quarantaine de centim�tres pour six kilogrammes, avec un corps rond, de courtes pattes et une queue aussi longue que son corps.",
    "La flamme qui br�le au bout de sa queue indique l'humeur de ce Pok�mon. Elle vacille lorsque Salam�che est content." };
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

int ChooseInt(std::mt19937& gen, int min, int max) {

    std::uniform_int_distribution<int> dist(min, max);
    int randomLevel = dist(gen);
    return randomLevel;
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
    int level = ChooseInt(gen, 1, 21);
    int health = ChooseInt(gen, 20, 51);

    return Pokemon(name, level, description, health, type);
}
