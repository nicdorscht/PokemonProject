#pragma once

#include "Move.h"

extern PokemonType normal;

class BodySlam : public Move {
public:
	BodySlam() : Move("Body Slam", normal, false, 85, 100, 15, 0) {}
};