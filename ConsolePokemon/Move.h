#pragma once

#include "BasePokemon.h"
#include <vector>
#include <string>

class Move
{
protected:
	std::string move_name;

	PokemonType move_type;

	bool is_special;

	int power;
	int accuracy;
	int pp;

	//Stat Changes
	int stat_change = 0;
	int stages = 0;
	int stat_chance = 0;
	bool on_enemy = true;

	//Recoil & Life steal, positive for life steal, negative for recoil
	float recoil_percent;

public:
	Move(std::string new_name, PokemonType new_move_type, bool new_is_special, int new_power, int new_accuracy, int new_pp, float new_recoil);
	Move(std::string new_name, PokemonType new_move_type, bool new_is_special, int new_power, int new_accuracy, int new_pp, float new_recoil, int new_stat_change, int new_stages, bool new_on_enemy, int new_stat_chance);
	~Move();
	std::string get_move_name();

	PokemonType get_move_type();

	std::vector<int> get_move_info();

	virtual void use_move(BasePokemon *user, BasePokemon *target);
};