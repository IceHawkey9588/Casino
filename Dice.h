#include "Player.h"
#include <iostream>

struct Dice{
    public:
        Dice(Player& player);
        ~Dice();

        void startGame(Player& player);
};