#pragma once

#include "BasePokemon.h"
#include "StoneEdge.h"
#include "FocusBlast.h"
#include "CrossChop.h"
#include "ThunderPunch.h"

extern PokemonType fighting;

class Machamp : public BasePokemon {
public:
	Machamp() : BasePokemon("Machamp", { fighting }, { new StoneEdge(), new FocusBlast(), new CrossChop(), new ThunderPunch() }, 100, 384, 394, 284, 251, 295, 229) {}
};