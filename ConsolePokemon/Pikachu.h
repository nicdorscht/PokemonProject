#pragma once

#include "PokemonType.h"
#include "BasePokemon.h"
#include "VoltTackle.h"
#include "IronTail.h"
#include "DoubleTeam.h"
#include "ThunderBolt.h"

extern PokemonType electric;

class Pikachu : public BasePokemon {
public:
	Pikachu() : BasePokemon("Pikachu", { electric }, { new VoltTackle(), new IronTail(), new DoubleTeam(), new ThunderBolt() }, 100, 274, 229, 196, 436, 218, 306) {}
};