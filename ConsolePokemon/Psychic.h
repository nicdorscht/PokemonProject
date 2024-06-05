#pragma once

#include "Move.h"

extern PokemonType psychic;

class Psychic : public Move {
public:
	Psychic() : Move("Psychic", psychic, true, 90, 100, 10, 0, 4, -1, true, 33.2f) {}
};