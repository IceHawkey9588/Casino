#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <vector>
#include "Player.h"
#include "DorN.h"
#include "Dice.h"
#include "Login.h"

using namespace std;

int main()
{
    int selection;
    srand(time(0));
    Login login;
    auto nbwl = login.getPlayer();
    Player player(get<0>(nbwl), get<1>(nbwl), get<2>(nbwl), get<3>(nbwl));
    cout << "Welcome back " << player.getName() << "! Select your game:" << endl;
    cout << "1. Double or Nothing\n"
         << "2. BlackJack\n"
         << "3. Poker\n"
         << "4. Dice\n"
         << "5. Roullete\n"
         << endl;
         
    cin >> selection;
    if(selection == 1){DorN dorn(player);}
    else if(selection == 2){}
    else if(selection == 3){}
    else if(selection == 4){Dice dice(player);}
    else if(selection == 5){}
    else {cout << "Bad selection" << endl;};
    return 0;
}
