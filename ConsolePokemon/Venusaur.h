#pragma once

#include "BasePokemon.h"

extern PokemonType grass;
extern PokemonType poison;

class Venusaur : public BasePokemon {
public:
	Venusaur() : BasePokemon("Venusaur", { grass, poison }, {}, 100, 364, 289, 291, 328, 328, 284) {}
};