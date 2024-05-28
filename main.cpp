#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <vector>
#include "Player.h"
#include "DorN.h"
#include "Dice.h"
#include "Login.h"
#include "BJ.h"


using namespace std;
/**
 * @brief main code to test out the games and for user navigation.
*/
int main()
{
    int selection;
    srand(time(0));
    Login login;
    auto nbwl = login.getPlayer();
    Player player(get<0>(nbwl), get<1>(nbwl), get<2>(nbwl), get<3>(nbwl));
    while(true){
        cout << "\nWelcome back " << player.getName() << "! Select your game:" << endl;
        cout << "1. Double or Nothing\n"
            << "2. BlackJack\n"
            << "3. Poker\n"
            << "4. Dice\n"
            << "5. Roullete\n"
            << "6. Get your balance report" << endl;
        cin >> selection;
        if(selection == 1){DorN dorn(player); login.changeCSV(player.getBalance(), player.getWins(), player.getLosses()); }
        else if(selection == 2){BJ bj(player);login.changeCSV(player.getBalance(), player.getWins(), player.getLosses());}
        else if(selection == 3){}
        else if(selection == 4){Dice dice(player); login.changeCSV(player.getBalance(), player.getWins(), player.getLosses());}
        else if(selection == 5){}
        else if(selection == 6){cout << "\nYour balance is: " << player.getBalance() << "$\n";}
        else {cout << "Bad selection" << endl;};
    }

    return 0;
}
