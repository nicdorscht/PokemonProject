#include "Player.h"
#include "Move.h"
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::cin;

extern bool gameOver;

Player::Player(std::vector<BasePokemon *> new_pokemon_list) :
	pokemon_list(new_pokemon_list)
{}

Player::~Player() {
	for (int i = 0; i < pokemon_list.size(); i++) {
		delete pokemon_list[i];
	}
};

std::vector<BasePokemon *> Player::get_pokemon_list() {
	return pokemon_list;
}

void Player::change_current_pokemon(BasePokemon *new_pokemon) {
	current_pokemon = new_pokemon;
}

BasePokemon * Player::get_current_pokemon() {
	return current_pokemon;
}

void Player::PokemonSwitch() {

	bool allFainted = true;

	for (int i = 0; i < pokemon_list.size(); i++) {
		if (pokemon_list[i]->get_stats()[1] > 0) { allFainted = false; }
	}

	if (allFainted) { gameOver = true; return; }

	cout << "Choose a Pokemon: \n";

	for (int i = 0; i < pokemon_list.size(); i++) {
		cout << i + 1 << " " << pokemon_list[i]->get_name() << "\tHP: " << pokemon_list[i]->get_stats()[1] << "\n";
	}

	while (true) {
		std::string switch_choice = "";
		int switch_int = 0;

		while (switch_choice == "") { cin >> switch_choice; }
		switch_int = stoi(switch_choice);

		if (!(switch_int < 1 || switch_int > pokemon_list.size())) {
			if (pokemon_list[switch_int - 1]->get_stats()[1] <= 0) {
				cout << pokemon_list[switch_int - 1]->get_name() << " has no health remaining!\n";
			}
			else {
				change_current_pokemon(pokemon_list[switch_int - 1]);
				cout << "Switched to " << pokemon_list[switch_int - 1]->get_name() << "!\n";
				break;
			}
		}
	}
}

void Player::play_turn(Player *target_player) {

	if (current_pokemon->get_stats()[1] <= 0) {
		PokemonSwitch();
		return;
	}

	cout << "What will " << current_pokemon->get_name() << " do?\n" << "1 Attack\n" << "2 Switch\n";

	std::string player_choice = "";
	BasePokemon *target_pokemon = target_player->get_current_pokemon();
	int player_choice_int = 0;

	while (!(player_choice_int == 1 || player_choice_int == 2)) {
		cin >> player_choice;

		try {
			player_choice_int = stoi(player_choice);
		}
		catch (std::string invalid) {
			cout << "Invalid.\n";
		}
	}

	if (player_choice_int == 1) {
		std::vector<Move *> moves = current_pokemon->get_moves();

		for (int i = 0; i < moves.size(); i++) {
			cout << i + 1 << " " << moves[i]->get_move_name() << " PP: " << moves[i]->get_move_info()[2] << "\n";
		}

		std::string move_choice = "";
		int move_choice_int = 0;

		while (move_choice_int > moves.size() || move_choice_int < 1) {
			cin >> move_choice;

			try {
				move_choice_int = stoi(move_choice);
			}
			catch (std::string invalid) {
				cout << "Invalid";
			}
		}

		moves[stoi(move_choice) - 1]->use_move(current_pokemon, target_pokemon);
		
		if (target_pokemon->get_stats()[1] <= 0) { std::cout << target_pokemon->get_name() << " fainted!\n"; }
		
	}
	else if (player_choice_int == 2) {
		PokemonSwitch();
	}
}