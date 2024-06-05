#pragma once

#include "BasePokemon.h"
#include "Psychic.h"
#include "GigaDrain.h"
#include "WoodHammer.h"
#include "LeafStorm.h"

extern PokemonType psychic;
extern PokemonType grass;

class Exeggutor : public BasePokemon {
public:
	Exeggutor() : BasePokemon("Exeggutor", { psychic, grass }, { new Psychic(), new GigaDrain(), new WoodHammer(), new LeafStorm() }, 100, 394, 317, 295, 383, 273, 229) {}
};