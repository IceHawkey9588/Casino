#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Player.h"

using namespace std;

struct Login
{
private:
    int counter = 0;
    int playerNum;
    vector<string> names;
    vector<double> balance;
    vector<int> wins;
    vector<int> losses;
public:
    tuple<std::string, double, int, int> getPlayer();
    void changeCSV(double bet, int additionW, int additionL);
    void printList();
};
