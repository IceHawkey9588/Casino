#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

using namespace std;

struct Login
{
public:
    tuple<std::string, double, int, int> getPlayer();
};
