#pragma once

#include "BasePokemon.h"

extern PokemonType normal;

class Snorlax : public BasePokemon {

public:
	Snorlax() : BasePokemon("Snorlax", { normal }, { }, 100, 524, 350, 251, 251, 350, 174) {}
};