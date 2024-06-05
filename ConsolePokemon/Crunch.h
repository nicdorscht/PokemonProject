#pragma once

#include "Move.h"

extern PokemonType dark;

class Crunch : public Move {
public:
	Crunch() : Move("Crunch", dark, false, 80, 100, 15, 0, 4, -1, true, 30) {}
};