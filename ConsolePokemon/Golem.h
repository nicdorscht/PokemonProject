#pragma once

#include "BasePokemon.h"
#include "Earthquake.h"
#include "GyroBall.h"
#include "StoneEdge.h"
#include "Explosion.h"

extern PokemonType rock;
extern PokemonType ground;

class Golem : public BasePokemon {
public:
	Golem() : BasePokemon("Golem", { rock, ground }, { new Earthquake(), new GyroBall(), new StoneEdge(), new Explosion() }, 100, 364, 372, 394, 229, 251, 207) {}
};