#pragma once

#include "Move.h"

extern PokemonType grass;

class WoodHammer : public Move {
public:
	WoodHammer() : Move("Wood Hammer", grass, false, 120, 100, 15, -0.33) {}
};