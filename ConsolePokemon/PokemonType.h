#pragma once

#include <string>
#include <vector>
using namespace std;

class PokemonType
{
	string type_name;

	//Store type weaknesses on defence only
	vector<string> strengths;
	vector<string> weaknesses;
	vector<string> immunities;

public:
	PokemonType(string new_name, vector<string> new_weaknesses, vector<string> new_strengths);
	PokemonType(string new_name, vector<string> new_weaknesses, vector<string> new_strengths, vector<string> new_immunities);
	~PokemonType();

	string get_type_name();
	vector<string> get_weaknesses();
	vector<string> get_strengths();
	vector<string> get_immunities();
};

