#pragma once

#include "Move.h"

extern PokemonType normal;

class DoubleTeam : public Move {
public:
	DoubleTeam() : Move("Double Team", normal, false, 0, -1, 15, 0, 7, 1, false, 100) {}
};