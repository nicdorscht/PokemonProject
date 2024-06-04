#pragma once

#include "Move.h"

extern PokemonType steel;

class FlashCannon : public Move {
public:
	FlashCannon() : Move("Flash Cannon", steel, true, 80, 100, 10, 0, 4, 1, true, 10) {}
};