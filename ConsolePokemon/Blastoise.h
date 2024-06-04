#pragma once
#include "BasePokemon.h"

#include "Hydropump.h"
#include "Earthquake.h"
#include "IceBeam.h"
#include "MegaKick.h"

extern PokemonType water;

class Blastoise :
    public BasePokemon
{
public:
    Blastoise() : BasePokemon("Blastoise", { water }, { new Hydropump(), new Earthquake(), new IceBeam(), new MegaKick()}, 100, 362, 291, 328, 295, 339, 280) {}
};

