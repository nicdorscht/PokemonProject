#pragma once

#include "Move.h"

extern PokemonType ice;

class Blizzard : public Move {
public:
	Blizzard() : Move("Blizzard", ice, true, 110, 70, 5, 0) {}
};