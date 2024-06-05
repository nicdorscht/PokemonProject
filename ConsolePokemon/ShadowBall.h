#pragma once

#include "Move.h"

extern PokemonType ghost;

class ShadowBall : public Move {
public:
	ShadowBall() : Move("Shadow Ball", ghost, true, 80, 100, 15, 0, 4, -1, true, 30) {}
};