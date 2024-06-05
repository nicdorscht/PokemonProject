#pragma once

#include "Move.h"

extern PokemonType electric;

class ThunderPunch : public Move {
public:
	ThunderPunch() : Move("Thunder Punch", electric, false, 75, 100, 15, 0) {}
};