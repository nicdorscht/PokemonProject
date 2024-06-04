#pragma once

#include "Move.h"

extern PokemonType ground;

class Earthquake : public Move {
public:
	Earthquake() : Move("Earthquake", ground, false, 100, 100, 10, 0) {}
};