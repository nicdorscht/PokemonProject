#pragma once

#include "Move.h"

extern PokemonType poison;

class SludgeBomb : public Move {
public:

	SludgeBomb() : Move("Sludge Bomb", poison, true, 90, 100, 10, 0) {}
};