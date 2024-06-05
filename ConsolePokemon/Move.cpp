#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

#include "Move.h"
#include "PokemonType.h"
#include "BasePokemon.h"

Move::Move(std::string new_name, PokemonType new_move_type, bool new_is_special, int new_power, int new_accuracy, int new_pp, float new_recoil) :
	move_name(new_name),
	move_type(new_move_type),
	is_special(new_is_special),
	power(new_power),
	accuracy(new_accuracy),
	pp(new_pp),
	recoil_percent(new_recoil)
{}

Move::Move(std::string new_name, PokemonType new_move_type, bool new_is_special, int new_power, int new_accuracy, int new_pp, float new_recoil, int new_stat_change, int new_stages, bool new_on_enemy, int new_stat_chance) :
	move_name(new_name),
	move_type(new_move_type),
	is_special(new_is_special),
	power(new_power),
	accuracy(new_accuracy),
	pp(new_pp),
	recoil_percent(new_recoil),
	stat_change(new_stat_change),
	stages(new_stages),
	on_enemy(new_on_enemy),
	stat_chance(new_stat_chance)
{}

Move::~Move() {}

std::string Move::get_move_name() {
	return move_name;
}

PokemonType Move::get_move_type() {
	return move_type;
}

std::vector<int> Move::get_move_info() {
	return { power, accuracy, pp };
}

void Move::use_move(BasePokemon *user, BasePokemon *target) {

	float damage_multiplier = 1.0f;
	int damage;
	float STAB = 1.0f;
	int attack;
	int defence;
	int crit = 1;
	int crit_chance = 25;
	float random;
	int acc_check = rand() % 101;
	int stat_check = rand() % 101;
	float modified_accuracy = accuracy * user->get_stats()[7] * target->get_stats()[8];

	//Check if guaranteed hit
	if (accuracy < 0) {
		modified_accuracy = 100;
	}

	//Determine multiplier based on typing
	std::vector<PokemonType> target_types = target->get_types();

	for (int i = 0; i < target_types.size(); i++) {

		std::vector<std::string> weaknesses = target_types[i].get_weaknesses();
		std::vector<std::string> strengths = target_types[i].get_strengths();
		std::vector<std::string> immunities = target_types[i].get_immunities();
		std::string name = move_type.get_type_name();

		for (int j = 0; j < weaknesses.size(); j++) {
			if (weaknesses[j] == name) { damage_multiplier *= 2; }
		}
		for (int k = 0; k < strengths.size(); k++) {
			if (strengths[k] == name) { damage_multiplier /= 2; }
		}
		for (int l = 0; l < immunities.size(); l++) {
			if (immunities[l] == name) { damage_multiplier *= 0; }
		}
	}

	//Set attack and defence based on if a special move or not
	if (!is_special) {
		attack = user->get_stats()[3];
		defence = target->get_stats()[4];
	}
	else {
		attack = user->get_stats()[5];
		defence = target->get_stats()[6];
	}

	//Determine if STAB should be used
	for (int i = 0; i < user->get_types().size(); i++) {
		if (move_type.get_type_name() == user->get_types()[i].get_type_name()) { STAB = 1.5f; }
	}

	//Roll for crit, 1/24 chance
	if (rand() % crit_chance == 24) { crit = 2; }

	//Random Aspect, rand int between 217 and 255 int divided by 255
	random = round((rand() % (256 - 217 + 1) + 217) / 255);

	if (random < 1) { random = 1; }

	//Solve for damage using gen 1 damage formula
	damage = round(((((((2 * user->get_stats()[0] * crit) / 5) + 2) * power * attack / defence) / 50) + 2) * STAB * damage_multiplier * random);

	//Moves should always do at least 1 damage
	if (damage < 1 && damage_multiplier != 0) { damage = 1; }

	std::cout << user->get_name() << " used " << move_name << "!\n";

	//Accuracy Check, set to 0 if misses
	if (acc_check <= modified_accuracy) {
		//Damage target, change stats and decrement pp
		target->change_health(-damage);

		if (stat_change != 0 && stat_check <= stat_chance) {
			if (on_enemy) {
				target->change_stats(stat_change, stages);
			}
			else {
				user->change_stats(stat_change, stages);
				//End move if only a stat raising move
				if (power == 0) { return; }
			}
		}

		//Deal recoil damage or add life steal
		if (recoil_percent != 0) {
			if ((damage * recoil_percent) + user->get_stats()[1] > user->get_base_stats()[1]) {
				user->change_health(user->get_base_stats()[1] - user->get_stats()[1]);
			}
			else {
				user->change_health(damage * recoil_percent);
			}
		}
		

		pp--;

		//Print info to console
		std::string crit_text = crit > 1 ? "A critical hit!\n" : "";
		std::string effective_text = damage_multiplier > 1 ? "It's super effective!\n" : damage_multiplier == 0 ? "It doesn't affect " + target->get_name() + "...\n" : damage_multiplier < 1 ? "It's not very effective...\n" : "";
		std::string recoil_text = recoil_percent > 0 ? target->get_name() + "'s health was drained!\n" : recoil_percent < 0 ? user->get_name() + "was hit with recoil!\n" : "";

		std::cout << crit_text << effective_text << recoil_text;
	}
	else {
		std::cout << move_name << " missed!\n";
	}
}
