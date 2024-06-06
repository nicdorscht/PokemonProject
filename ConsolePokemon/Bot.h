#pragma once
#include "Player.h"

class Bot :
    public Player
{
public:
    using Player::Player;

    void play_turn(Player* target_player) override;
};

