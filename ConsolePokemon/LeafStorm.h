#pragma once

#include "Move.h"

extern PokemonType grass;

class LeafStorm : public Move {
public:
	LeafStorm() : Move("Leaf Storm", grass, true, 130, 90, 5, 0, 3, -2, false, 100) {}
};