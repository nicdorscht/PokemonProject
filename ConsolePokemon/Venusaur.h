#pragma once

#include "BasePokemon.h"
#include "BodySlam.h"
#include "GigaDrain.h"
#include "SludgeBomb.h"
#include "DoubleTeam.h"

extern PokemonType grass;
extern PokemonType poison;

class Venusaur : public BasePokemon {
public:
	Venusaur() : BasePokemon("Venusaur", { grass, poison }, { new BodySlam(), new GigaDrain(), new SludgeBomb(), new DoubleTeam() }, 100, 364, 289, 291, 328, 328, 284) {}
};