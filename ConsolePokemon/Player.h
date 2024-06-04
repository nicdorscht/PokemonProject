#pragma once

#include "BasePokemon.h"
#include <vector>

class Player
{
	std::vector<BasePokemon *> pokemon_list;

	BasePokemon * current_pokemon = pokemon_list[0];

public:
	Player(std::vector<BasePokemon *> new_pokemon_list);
	~Player();

	std::vector<BasePokemon *> get_pokemon_list();
	
	void change_current_pokemon(BasePokemon *new_pokemon);
	BasePokemon * get_current_pokemon();
	void PokemonSwitch();

	void play_turn(Player *target_player);
};

