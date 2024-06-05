#pragma once

#include "Move.h"
#include <iostream>

extern PokemonType normal;

class Explosion : public Move {
public:
	Explosion() : Move("Explosion", normal, false, 250, 100, 5, -10000.0f) {}
};