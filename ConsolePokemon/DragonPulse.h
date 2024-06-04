#pragma once

#include "Move.h"

extern PokemonType dragon;

class DragonPulse : public Move {
public:
	DragonPulse() : Move("Dragon Pulse", dragon, true, 85, 100, 10, 0) {}
};