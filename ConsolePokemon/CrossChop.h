#pragma once

#include "Move.h"
#include <iostream>

extern PokemonType fighting;

class CrossChop : public Move {
public:
	CrossChop() : Move("Cross Chop", fighting, false, 100, 80, 5, 0) {}

	void use_move(BasePokemon* user, BasePokemon* target) override {
		float damage_multiplier = 1.0f;
		int damage;
		float STAB = 1.0f;
		int attack;
		int defence;
		int crit = 1;
		int crit_chance = 25;
		float random;
		int acc_check = rand() % 101;
		float modified_accuracy = accuracy * user->get_stats()[7] * target->get_stats()[8];

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
		if (rand() % crit_chance == 8) { crit = 2; }

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


			pp--;

			//Print info to console
			std::string crit_text = crit > 1 ? "A critical hit!\n" : "";
			std::string effective_text = damage_multiplier > 1 ? "It's super effective!\n" : damage_multiplier == 0 ? "It doesn't affect " + target->get_name() + "...\n" : damage_multiplier < 1 ? "It's not very effective...\n" : "";

			std::cout << crit_text << effective_text;
		}
		else {
			std::cout << move_name << " missed!\n";
		}
	}
};