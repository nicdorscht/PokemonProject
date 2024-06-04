#include "PokemonType.h"

#include <iostream>
#include <string>
#include <vector>

PokemonType::PokemonType(std::string new_name, std::vector<std::string> new_weaknesses, std::vector<std::string> new_strengths) :
	type_name(new_name),
	weaknesses(new_weaknesses),
	strengths(new_strengths)
	{}

PokemonType::PokemonType(std::string new_name, std::vector<std::string> new_weaknesses, std::vector<std::string> new_strengths, std::vector<std::string> new_immunities) :
	type_name(new_name),
	weaknesses(new_weaknesses),
	strengths(new_strengths),
	immunities(new_immunities)
{}

PokemonType::~PokemonType() {}

std::vector<std::string> PokemonType::get_weaknesses() {
	return weaknesses;
}

std::vector<std::string> PokemonType::get_strengths() {
	return strengths;
}

std::vector<std::string> PokemonType::get_immunities() {
	return immunities;
}

std::string PokemonType::get_type_name() {
	return type_name;
}
