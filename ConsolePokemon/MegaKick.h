#pragma once

#include "Move.h"

extern PokemonType normal;

class MegaKick : public Move {
public:
	MegaKick() : Move("Mega Kick", normal, false, 120, 75, 5, 0) {}
};