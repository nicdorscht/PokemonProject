#pragma once

#include "PokemonType.h"
#include "BasePokemon.h"
#include "BodySlam.h"
#include "Brine.h"
#include "Blizzard.h"
#include "Psychic.h"

extern PokemonType water;
extern PokemonType ice;

class Lapras : public BasePokemon {
public:
	Lapras() : BasePokemon("Lapras", { water, ice }, { new BodySlam(), new Brine(), new Blizzard(), new Psychic() }, 100, 464, 295, 284, 295, 317, 240) {}
};