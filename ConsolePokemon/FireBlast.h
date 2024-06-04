#pragma once

#include "Move.h"

extern PokemonType fire;

class FireBlast : public Move {
public:
	FireBlast() : Move("Fire Blast", fire, true, 110, 85, 5, 0) {}
};