#include "Dice.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Constructs a new instance of the Dice class.
 * 
 * This constructor initializes a new instance of the Dice class and starts the game for the specified player.
 * 
 * @param player The player object for whom the game is being started.
 */
Dice::Dice(Player& player){
    startGame(player);
}

Dice::~Dice(){
}

/**
 * Starts the dice game.
 * 
 * This function allows the player to play the dice game. It takes a reference to a Player object as a parameter.
 * The player is prompted to enter their bet and choose what to bet on (red, blue, or tie). The dice are rolled and
 * the outcome is determined. If the player wins, their balance is increased and the winnings are displayed. If the
 * player loses, their balance is decreased and a message is displayed. The player can choose to play again or quit
 * the game.
 * 
 * @param player The player object for whom the game is being started.
 */
void Dice::startGame(Player& player){
    int bet;
    string choice;
    bool done = false;

    cout << "\nWelcome to the dice game!" << endl;
    cout << "Your initial balance is: $" << player.getBalance() << endl;
    while (player.getBalance() > 0 && !done)
    {
        cout << "\nEnter your bet: $";
        cin >> bet;
        if (bet > player.getBalance())
        {
            cout << "You don't have enough balance to make this bet. Try again." << endl;
            continue;
        }
        cout << "Choose what to bet on: red, blue or tie:" << endl;
        cin >> choice;

        int red = rand() % 6 + 1;
        int blue = rand() % 6 + 1;
        cout << "The dice rolled: red(" << red << ") and blue(" << blue << ")" << endl;
        if (red == blue && choice == "tie")
        {
            player.increaseBalance(bet * 5);
            player.incrementWins();
            cout << "Congratulations! You won. +" << bet * 5 << "$!\nYour new balance is: $" << player.getBalance() << endl;
        }
        else if (red > blue && choice == "red")
        {
            player.increaseBalance(bet);
            player.incrementWins();
            cout << "Congratulations! You won. +" << bet << "$!\nYour new balance is: $" << player.getBalance() << endl;
        }
        else if (red < blue && choice == "blue")
        {
            player.increaseBalance(bet);
            player.incrementWins();
            cout << "Congratulations! You won. +" << bet << "$!\nYour new balance is: $" << player.getBalance() << endl;
        }
        else
        {
            player.decreaseBalance(bet);
            player.incrementLosses();
            cout << "Sorry, you lost. Your new balance is: $" << player.getBalance() << endl;
        }
        if (player.getBalance() == 0)
        {
            cout << "You have no more balance to play with." << endl;
            break;
        }

        cout << "Do you want to play again? (yes/no): ";
        while(1){
            string answer;
            cin >> answer;
            if(answer == "yes"){
                done = false;
                break;
            }else if(answer == "no"){
                done = true;
                break;
            }else {
                cout << "Invalid input. Type \"yes\" or \"no\": ";
            }
        }
    }
}