#pragma once

#include "BasePokemon.h"
#include "Blizzard.h"
#include "MegaKick.h"
#include "Crunch.h"
#include "ShadowBall.h"

extern PokemonType normal;

class Snorlax : public BasePokemon {

public:
	Snorlax() : BasePokemon("Snorlax", { normal }, { new Blizzard(), new MegaKick(), new Crunch(), new ShadowBall() }, 100, 524, 350, 251, 251, 350, 174) {}
};