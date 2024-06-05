#pragma once

#include "BasePokemon.h"
#include "ShadowBall.h"
#include "SludgeBomb.h"
#include "ThunderBolt.h"
#include "Psychic.h"

extern PokemonType poison;
extern PokemonType ghost;

class Gengar : public BasePokemon {
public:
	Gengar() : BasePokemon("Gengar", { poison, ghost }, { new SludgeBomb(), new ShadowBall(), new Psychic, new ThunderBolt() }, 100, 324, 251, 240, 394, 273, 350) {}
};