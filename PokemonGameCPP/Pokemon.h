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
	std::string GetName() const;
	int GetLevel() const;
	std::string GetDescription() const;
	int GetHealth() const;
	std::string GetType() const;
};



