#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Hand.h"

struct BJ
{
public:
    BJ(Player& player);
    ~BJ();
    void startGame(Player& player);
    void rndCard(int[], Hand&);
    void giveCards(int[], Hand&, Hand&);
    void showCards(Hand&, Hand&);
    void printCard(int);
    void calculateScore(Hand&);
    void dealersMove(int[],Hand&, Hand&);
};
#pragma once
