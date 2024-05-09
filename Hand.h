#ifndef HAND_H
#define HAND_H

#include <string>

class Hand{
public:
    Hand();
    int nCards[10];
    int aces;
    int score;
    int altScore;
    int n;
    bool end;
};

#endif