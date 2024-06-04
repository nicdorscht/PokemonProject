#pragma once
#include "BasePokemon.h"
#include "Flamethrower.h"
#include "Slash.h"
#include "FireBlast.h"
#include "Earthquake.h"

extern PokemonType fire;
extern PokemonType flying;

class Charizard :
    public BasePokemon
{
public:

    Charizard() : BasePokemon("Charizard", { fire, flying }, { new Flamethrower(), new Slash(), new FireBlast(), new Earthquake() }, 100, 360, 293, 280, 348, 295, 328) {}
};

