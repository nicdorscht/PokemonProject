#pragma once
#include "BasePokemon.h"
#include "Slash.h"
#include "FireBlast.h"
#include "AirSlash.h"
#include "DragonPulse.h"

extern PokemonType fire;
extern PokemonType flying;

class Charizard :
    public BasePokemon
{
public:

    Charizard() : BasePokemon("Charizard", { fire, flying }, { new DragonPulse(), new Slash(), new FireBlast(), new AirSlash()}, 100, 360, 293, 280, 348, 295, 328) {}
};

