#pragma once

#include "Move.h"

extern PokemonType fighting;

class FocusBlast : public Move {
public:
	FocusBlast() : Move("Focus Blast", fighting, true, 120, 70, 5, 0, 4, 1, true, 10) {}
};