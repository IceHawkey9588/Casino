#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "DorN.h"

using namespace std;

int main() {
    Player player;
    srand(time(0));

    DorN dorn(player);

    return 0;
}
