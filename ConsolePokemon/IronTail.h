#pragma once

#include "Move.h"

extern PokemonType steel;

class IronTail : public Move {
public:
	IronTail() : Move("Iron Tail", steel, false, 100, 75, 15, 0, 2, 1, true, 30) {}
};