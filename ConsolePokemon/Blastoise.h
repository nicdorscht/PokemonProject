#pragma once
#include "BasePokemon.h"

#include "Hydropump.h"
#include "Blizzard.h"
#include "FlashCannon.h"
#include "FocusBlast.h"

extern PokemonType water;

class Blastoise :
    public BasePokemon
{
public:
    Blastoise() : BasePokemon("Blastoise", { water }, { new Hydropump(), new Blizzard(), new FlashCannon(), new FocusBlast() }, 100, 362, 291, 328, 295, 339, 280) {}
};

