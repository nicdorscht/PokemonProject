#pragma once

#include "BasePokemon.h"
#include <vector>
#include <string>

class Player
{
protected:
	std::string player_name;
	std::vector<BasePokemon *> pokemon_list;

	BasePokemon * current_pokemon = pokemon_list[0];

public:
	Player(std::string new_name, std::vector<BasePokemon *> new_pokemon_list);
	~Player();

	std::vector<BasePokemon *> get_pokemon_list();
	
	void change_current_pokemon(BasePokemon *new_pokemon);
	BasePokemon * get_current_pokemon();
	void PokemonSwitch();
	std::string get_name();

	virtual void play_turn(Player *target_player);
};

