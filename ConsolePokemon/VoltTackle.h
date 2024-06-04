#pragma once

#include "Move.h"

extern PokemonType electric;

class VoltTackle : public Move {
public:
	VoltTackle() : Move("Volt Tackle", electric, false, 120, 100, 15, -0.333f) {}
};