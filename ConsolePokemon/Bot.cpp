#include "Bot.h"
#include "Move.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
extern bool gameOver;
extern string loser;
extern string winner;

void Bot::play_turn(Player* target_player) {

	if (gameOver && winner == "") {
		winner = player_name;
		return;
	}

	bool allDead = true;

	//Switch if dead
	if (current_pokemon->get_stats()[1] <= 0) {
		for (int i = 0; i < pokemon_list.size(); i++) {
			if (pokemon_list[i]->get_stats()[1] > 0) {
				change_current_pokemon(pokemon_list[i]);
				allDead = false;
				break;
			}
		}
	}
	else {
		allDead = false;
	}

	if (allDead) {
		gameOver = true;
		loser = player_name;
		return;
	}

	cout << "BOT RED:\n";

	vector<Move *> moves = current_pokemon->get_moves();
	vector<double> move_weights{ 1.0, 1.0, 1.0, 1.0, 0.5 };

	bool enemy_clean_stats = true;
	bool user_clean_stats = true;

	//Weightings
	float effective_weight = 2;
	float not_effective_weight = 2;
	float immune_weight = 0;
	float enenmy_stats_weight = 1.1;
	float user_stats_weight = 1.3;
	float user_stats_guaranteed_weight = 1.7;
	float power_weight = 0.0025;

	//Get target pokemon's stats and then remove level and store health separetely
	vector<int> enemy_base_stats = target_player->get_current_pokemon()->get_base_stats();
	vector<int> enemy_stats = target_player->get_current_pokemon()->get_stats();
	int enemy_health = target_player->get_current_pokemon()->get_stats()[1];

	vector<int> user_stats = current_pokemon->get_stats();
	vector<int> user_base_stats = current_pokemon->get_base_stats();
	int user_health = current_pokemon->get_base_stats()[1];

	enemy_base_stats.erase(enemy_base_stats.begin(), enemy_base_stats.begin() + 1);
	enemy_stats.erase(enemy_stats.begin(), enemy_stats.begin() + 1);

	user_base_stats.erase(user_base_stats.begin(), user_base_stats.begin() + 1);
	user_stats.erase(user_stats.begin(), user_stats.begin() + 1);

	int sum_base_stats = accumulate(user_base_stats.begin(), user_base_stats.end(), 0);
	int sum_stats = accumulate(user_stats.begin(), user_stats.end(), 0);

	//Check if enemy's stats have been changed
	if (enemy_stats != enemy_base_stats) {
		enemy_clean_stats = false;
	}

	if (sum_stats <= sum_base_stats) {
		user_clean_stats = false;
	}

	//Get pokemon types
	vector<PokemonType> enemy_types = target_player->get_current_pokemon()->get_types();
	vector<PokemonType> user_types = current_pokemon->get_types();

	//Loop through moves and increase or decrease value

	for (int i = 0; i < moves.size(); i++) {
		Move current_move = *moves[i];
		PokemonType move_type = current_move.get_move_type();

		for (int j = 0; j < enemy_types.size(); j++) {

			vector<string> type_strengths = enemy_types[j].get_strengths();
			vector<string> type_weaknesses = enemy_types[j].get_weaknesses();
			vector<string> type_immunities = enemy_types[j].get_immunities();

			if (find(type_strengths.begin(), type_strengths.end(), move_type.get_type_name()) != type_strengths.end()) {
				move_weights[i] *= effective_weight;
			}
			if (find(type_weaknesses.begin(), type_weaknesses.end(), move_type.get_type_name()) != type_weaknesses.end()) {
				move_weights[i] /= not_effective_weight;
			}
			if (find(type_immunities.begin(), type_immunities.end(), move_type.get_type_name()) != type_immunities.end() && current_move.get_move_info()[0] != 0) {
				move_weights[i] = immune_weight;
			}
		}

		if (enemy_clean_stats && current_move.get_move_info()[3] != 0) {
			move_weights[i] *= (current_move.get_move_info()[3] + enenmy_stats_weight);
		}

		if (user_clean_stats) {
			if (current_move.get_move_info()[3] > 0) {
				move_weights[i] *= (current_move.get_move_info()[3] + user_stats_weight);
			}
			else if (current_move.get_move_info()[3] < 0) {
				move_weights[i] = user_stats_guaranteed_weight;
			}
			
		}

		if (current_move.get_move_info()[0] != 0) {
			move_weights[i] *= 1 + (current_move.get_move_info()[0] * power_weight);
		}
	}

	int highest_weight = distance(move_weights.begin(), max_element(move_weights.begin(), move_weights.end()));

	current_pokemon->get_moves()[highest_weight]->use_move(current_pokemon, target_player->get_current_pokemon());
}