#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

struct DorN
{
public:
    DorN(Player& player);
    ~DorN();
    void startGame(Player& player);
};
