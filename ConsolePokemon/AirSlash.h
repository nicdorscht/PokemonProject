#pragma once

#include "Move.h"

extern PokemonType flying;

class AirSlash : public Move {
public:
	AirSlash() : Move("Air Slash", flying, true, 75, 95, 15, 0) {}
};