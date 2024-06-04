#pragma once
#include "Move.h"
#include "PokemonType.h"
extern PokemonType fire;

class Flamethrower :
    public Move
{
public :
    Flamethrower() : Move("Flamethrower", fire, true, 90, 100, 15) {}
};

