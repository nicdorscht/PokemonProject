#pragma once

#include "PokemonType.h"
#include "BasePokemon.h"

extern PokemonType water;
extern PokemonType ice;

class Lapras : public BasePokemon {
public:
	Lapras() : BasePokemon("Lapras", { water, ice }, {}, 100, 464, 295, 284, 295, 317, 240) {}
};