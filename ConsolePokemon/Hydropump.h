#pragma once
#include "Move.h"
#include "PokemonType.h"

extern PokemonType water;

class Hydropump :
    public Move
{
public:
    Hydropump() : Move("Hydro Pump", water, true, 110, 80, 5) {}
};

