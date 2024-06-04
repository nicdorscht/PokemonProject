#pragma once

#include "Move.h"

extern PokemonType electric;

class ThunderBolt : public Move {
public:
	ThunderBolt() : Move("Thunder Bolt", electric, true, 90, 100, 15, 0) {}
};