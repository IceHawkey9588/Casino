#include "Player.h"
#include <iostream>

struct Dice{
    private:
        Player player;
    public:
        Dice(Player player);
        ~Dice();

        void startGame();
};