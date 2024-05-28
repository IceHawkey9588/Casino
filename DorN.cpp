#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "DorN.h"

using namespace std;

/**
 * @brief Constructs a new instance of the DorN (Double or nothing) class.
 * 
 * This constructor initializes a new instance of the DorN class and starts the game for the specified player.
 * 
 * @param player The player object for whom the game is being started.
 */
DorN::DorN(Player& player)
{
    startGame(player);
}

DorN::~DorN()
{
}

/**
 * Starts the Double or Nothing game.
 * 
 * This function allows the player to play the Double or Nothing game.
 * The player is prompted to enter their bet and choose heads or tails.
 * The outcome is determined randomly, and the player's balance is updated accordingly.
 * The game continues until the player's balance reaches zero or the player chooses to exit.
 * At the end of the game, the total number of wins and losses is displayed.
 * 
 * @param player The player object for whom the game is being started.
 */
void DorN::startGame(Player& player)
{
    string choice;
    int bet;
    cout << "\nWelcome to the Double or Nothing game!" << endl;
    cout << "Your initial balance is: $" << player.getBalance() << endl;
    while (player.getBalance() > 0)
    {
        cout << "\nEnter your bet or -1 to exit: $\n";
        cin >> bet;
        if (bet == -1){
            return;
        }
        else if (bet > player.getBalance())
        {
            cout << "You don't have enough balance to make this bet. Try again." << endl;
            continue;
        }
        cout << "Choose heads or tails:";
        cin >> choice;
        int outcome = rand() % 2;
        if (choice == "heads")
        {
            if (outcome == 1)
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
        }
        else if (choice == "tails")
        {
            if (outcome == 0)
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
        }
        else
        {
            cout << "Invalid choice. Please enter 'heads' or 'tails'." << endl;
        }
        if (player.getBalance() == 0)
        {
            cout << "Game over! You've run out of balance." << endl;
            break;
        }
    }

    cout << "Thank you for playing!" << endl;
    cout << "Total Wins: " << player.getWins() << endl;
    cout << "Total Losses: " << player.getLosses() << endl;
}