#pragma once

#include <iostream>
#include <string>

class Pokemon
{
private:
	std::string name;
	int level;
	std::string description;
	int health;
	std::string type;
public:
	Pokemon(std::string name, int level, std::string description, int health, std::string type);
	~Pokemon();
	std::string GetName();
	int GetLevel();
	std::string GetDescription();
	int GetHealth();
	std::string GetType();
};

