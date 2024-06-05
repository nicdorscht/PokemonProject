#pragma once

#include "Move.h"

extern PokemonType grass;

class GigaDrain : public Move {
public:
	GigaDrain() : Move("Giga Drain", grass, true, 75, 100, 10, 0.5) {}
};