#pragma once

#include "Move.h"
#include "PokemonType.h"

extern PokemonType normal;

class Slash : public Move {
public:
	Slash() : Move("Slash", normal, false, 70, 100, 20) {}
};