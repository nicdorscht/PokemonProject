#pragma once

#include <string>
#include <vector>
#include "PokemonType.h"
#include "StatusEffect.h"

class Move;

class BasePokemon
{
protected:
	std::string name;

	std::vector<PokemonType> types;
	std::vector<Move *> moves;

	//Base Pokemon Stats
	int level;
	int health;
	int attack;
	int defence;
	int spattack;
	int spdefence;
	int speed;
	int accuracy = 1;
	int evasivness = 1;

	//Stat Modifiers
	float mod_attack = 1;
	float mod_defence = 1;
	float mod_spattack = 1;
	float mod_spdefence = 1;
	float mod_speed = 1;
	float mod_acc = 1;
	float mod_eva = 1;

	//Modified Stats
	int new_health = health;
	int new_attack = attack;
	int new_defence = defence;
	int new_spattack = spattack;
	int new_spdefence = spdefence;
	int new_speed = speed;
	int new_accuracy = accuracy;
	int new_evasivness = evasivness;

	//StatusEffect status_effect;
	bool fainted = false;

public :
	BasePokemon(std::string new_name, std::vector<PokemonType> new_types, std::vector<Move *> new_moves, int new_level, int new_health, int new_attack, int new_defence, int new_spattack, int new_spdefence, int new_speed);
	~BasePokemon();

	std::vector<int> get_stats();
	std::vector<int> get_base_stats();
	std::string get_name();
	void print_stats();
	std::vector<PokemonType> get_types();
	std::vector<Move *> get_moves();
	void change_health(int new_health);

	void change_stats(int stat, int stages);
};

