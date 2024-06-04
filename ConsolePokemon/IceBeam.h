#pragma once

#include "Move.h"

extern PokemonType ice;

class IceBeam : public Move {
public:
	IceBeam() : Move("Ice Beam", ice, true, 90, 100, 10, 0) {}
};