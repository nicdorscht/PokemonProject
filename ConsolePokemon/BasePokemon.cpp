#include "BasePokemon.h"
#include "PokemonType.h"
#include "Move.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

extern bool gameOver;

BasePokemon::BasePokemon(std::string new_name, std::vector<PokemonType> new_types, std::vector<Move *> new_moves, int new_level, int new_health, int new_attack, int new_defence, int new_spattack, int new_spdefence, int new_speed) :
	name(new_name),
	types(new_types),
	moves(new_moves),
	level(new_level),
	health(new_health),
	attack(new_attack),
	defence(new_defence),
	spattack(new_spattack),
	spdefence(new_spattack),
	speed(new_speed)
{}

BasePokemon::~BasePokemon() {
	for (int i = 0; i < moves.size(); i++) {
		delete moves[i];
	}
}

std::vector<int> BasePokemon::get_stats() {
	return { level, new_health, new_attack, new_defence, new_spattack, new_spdefence, new_speed, new_accuracy, new_evasivness };
}

std::vector<int> BasePokemon::get_base_stats() {
	return { level, health, attack, defence, spattack, spdefence, speed, accuracy, evasivness };
}

std::vector<PokemonType> BasePokemon::get_types() {
	return types;
}

std::string BasePokemon::get_name() {
	return name;
}

std::vector<Move *> BasePokemon::get_moves() {
	return moves;
}

void BasePokemon::print_stats() {
	//Name, Types, Health, Atk, Def, Sp. Atk, Sp. Def, Spd

	//Check and output length of type vector, only works since vector will never be longer than 2
	std::string type_string;

	if (types.size() > 1) { type_string = types[0].get_type_name() + ", " + types[1].get_type_name(); }
	else { type_string = types[0].get_type_name(); }

	std::cout
		<< "Name: " << name << std::endl
		<< "Types: " << type_string << std::endl
		<< "Health: " << health << std::endl
		<< "Attack: " << attack << std::endl
		<< "Defence: " << defence << std::endl
		<< "Sp. Attack: " << spattack << std::endl
		<< "Sp. Defence: " << spdefence << std::endl
		<< "Speed: " << speed << std::endl;
}

void BasePokemon::change_health(int health_change) {
	new_health += health_change;

	if (new_health <= 0) {
		new_health = 0;
		fainted = true;
	}

	std::cout << name << ": " << new_health << " HP\n";
}

void BasePokemon::change_stats(int stat, int stages) {
	float *stat_mod;
	int *change_stat;
	int base_stat;
	std::string updown;
	std::string stat_name;

	switch (stat)
	{
	case 1 :
		stat_mod = &mod_attack;
		change_stat = &new_attack;
		base_stat = attack;
		stat_name = "attack";
		break;
	case 2:
		stat_mod = &mod_defence;
		change_stat = &new_defence;
		base_stat = defence;
		stat_name = "defence";
		break;
	case 3:
		stat_mod = &mod_spattack;
		change_stat = &new_spattack;
		base_stat = spattack;
		stat_name = "special attack";
		break;
	case 4:
		stat_mod = &mod_spdefence;
		change_stat = &new_spdefence;
		base_stat = spdefence;
		stat_name = "special defence";
		break;
	case 5:
		stat_mod = &mod_speed;
		change_stat = &new_speed;
		base_stat = speed;
		stat_name = "speed";
		break;
	case 6:
		stat_mod = &mod_acc;
		change_stat = &accuracy;
		base_stat = accuracy;
		stat_name = "accuracy";
		break;
	case 7:
		stat_mod = &mod_eva;
		change_stat = &evasivness;
		base_stat = evasivness;
		stat_name = "evasivness";
		break;
	default:
		stat_mod = &mod_attack;
		change_stat = &attack;
		base_stat = attack;
		stat_name = "attack";
	}

	//Check for max modifier
	if (*stat_mod < 0.2f) {
		std::cout << "The " << stat_name << " of " << name << " couldn't be lowered!\n";
		return;
	}
	else if (*stat_mod > 2.0f) {
		std::cout << "The " << stat_name << " of " << name << " couldn't be raised!\n";
		return;
	}

	for (int i = 0; i < abs(stages); i++) {
		if (stages > 0) {
			*stat_mod += 0.2f;
			updown = " raised!\n";
		}
		else {
			*stat_mod -= 0.2f;
			updown = " lowered!\n";
		}
	}

	std::string sharp = "";
	if (abs(stages) > 1) { sharp = "sharply"; }

	*change_stat = round(base_stat * *(stat_mod));

	std::cout << name << "'s " << stat_name << " was " << sharp << updown;


}