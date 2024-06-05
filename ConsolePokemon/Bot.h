#pragma once
#include "Player.h"

class Bot :
    public Player
{
    void play_turn(Player* target_player) override;
};

