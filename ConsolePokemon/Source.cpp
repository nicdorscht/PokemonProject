#include <iostream>
#include <string>
#include "Charizard.h"
#include "Blastoise.h"
#include "Player.h"
#include "PokemonType.h"
#include <cstdlib>

#pragma region Type_Instanciation
PokemonType normal("Normal", {}, { "Fighting" }, { "Ghost" });
PokemonType fire("Fire", { "Water", "Ground", "Rock" }, { "Fire", "Grass", "Ice", "Bug" });
PokemonType water("Water", { "Grass", "Electric" }, { "Fire", "Water", "Ice", "Steel" });
PokemonType electric("Electric", { "Ground" }, { "Electric", "Flying", "Steel" });
PokemonType grass("Grass", { "Fire", "Ice", "Poison", "Flying", "Bug" }, { "Water", "Electric", "Grass", "Ground" });
PokemonType ice("Ice", { "Fire", "Fighting", "Rock", "Steel" }, { "Ice" });
PokemonType fighting("Fighting", { "Flying", "Psychic" }, { "Bug", "Rock", "Dark" });
PokemonType poison("Poison", { "Ground", "Psychic" }, { "Grass", "Fighting", "Poison" });
PokemonType ground("Ground", { "Water", "Grass", "Ice" }, { "Poison", "Rock" }, { "Electric" });
PokemonType flying("Flying", { "Electric", "Rock", "Ice" }, { "Grass", "Fighting", "Bug" }, { "Ground" });
PokemonType psychic("Psychic", { "Bug", "Ghost", "Dark" }, { "Fighting", "Psychic" });
PokemonType bug("Bug", { "Fire", "Flying", "Rock" }, { "Grass", "Fighting", "Ground " });
PokemonType rock("Rock", { "Water", "Grass", "Fighting", "Ground", "Steel" }, { "Normal", "Fire", "Poison", "Flying " });
PokemonType ghost("Ghost", { "Ghost", "Dark" }, { "Poison", "Bug" }, { "Normal", "Fighting" });
PokemonType dragon("Dragon", { "Ice", "Dragon" }, { "Fire", "Water", "Electric", "Grass" });
PokemonType dark("Dark", { "Fighting", "Bug" }, { "Ghost", "Dark" }, { "Psychic" });
PokemonType steel("Steel", { "Fire", "Fighting", "Ground" }, { "Normal", "Grass", "Ice", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Steel" }, { "Poison" });
#pragma endregion Type_Instanciation

bool gameOver = false;
std::string winner;

int main() {

	//Instantiate Players
	Player *player1 = new Player({ new Charizard(), new Blastoise()});
	Player *player2 = new Player({ new Blastoise() });

	int i = 0;

	//Game Loop
	while (true) {
		int player1_speed = player1->get_current_pokemon()->get_stats()[6];
		int player2_speed = player2->get_current_pokemon()->get_stats()[6];

		if (player1_speed > player2_speed) {
			if (gameOver) { std::cout << "Player 2 has no remaining pokemon... Player 1 wins!"; break;}
			std::cout << "Player 1: \n";
			player1->play_turn(player2);
			if (gameOver) { std::cout << "Player 1 has no remaining pokemon... Player 2 wins!"; break; }
			std::cout << "Player 2: \n";
			player2->play_turn(player1);
		}
		else if (player1_speed == player2_speed) {
			int first = rand() % 3;
			if (first == 1) {
				if (gameOver) { std::cout << "Player 2 has no remaining pokemon... Player 1 wins!"; break; }
				std::cout << "Player 1: \n";
				player1->play_turn(player2);
				if (gameOver) { std::cout << "Player 1 has no remaining pokemon... Player 2 wins!"; break;}
				std::cout << "Player 2: \n";
				player2->play_turn(player1);
			}
			else {
				if (gameOver) { std::cout << "Player 2 has no remaining pokemon... Player 1 wins!"; break;}
				std::cout << "Player 2: \n";
				player2->play_turn(player1);
				if (gameOver) { std::cout << "Player 1 has no remaining pokemon... Player 2 wins!"; break;}
				std::cout << "Player 1: \n";
				player1->play_turn(player2);
			}
		}
		else {
			if (gameOver) { std::cout << "Player 2 has no remaining pokemon... Player 1 wins!"; break; }
			std::cout << "Player 2: \n";
			player2->play_turn(player1);
			if (gameOver) { std::cout << "Player 1 has no remaining pokemon... Player 2 wins!"; break; }
			std::cout << "Player 1: \n";
			player1->play_turn(player2);
		}

		i++;
	}

	delete player1;
	delete player2;
}