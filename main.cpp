#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
private:
    int balance=1000;
    int wins=0;
    int losses=0;

public:
    int getBalance() const {
        return balance;
    }

    int getWins() const {
        return wins;
    }

    int getLosses() const {
        return losses;
    }

    void increaseBalance(int amount) {
        balance += amount;
    }
    void decreaseBalance(int amount) {
        balance -= amount;
    }

    void incrementWins() {
        wins++;
    }

    void incrementLosses() {
        losses++;
    }
};

int main() {
    Player player;
    int bet;
    string choice;
    srand(time(0));
    cout << "Welcome to the Double or Nothing game!" << endl;
    cout << "Your initial balance is: $" << player.getBalance() << endl;
    while (player.getBalance() > 0) {
        cout << "\nEnter your bet: $";
        cin >> bet;
        if (bet > player.getBalance()) {
            cout << "You don't have enough balance to make this bet. Try again." << endl;
            continue;
        }
        cout << "Choose heads or tails:";
        cin >> choice;
        int outcome = rand() % 2;
        if (choice == "heads") {
            if (outcome == 1) {
                player.increaseBalance(bet);
                player.incrementWins();
                cout << "Congratulations! You won. +"<<bet<<"$!\nYour new balance is: $" << player.getBalance() << endl;
            } else {
                player.decreaseBalance(bet);
                player.incrementLosses();
                cout << "Sorry, you lost. Your new balance is: $" << player.getBalance() << endl;
            }
        } else if (choice == "tails") {
            if (outcome == 0) {
                player.increaseBalance(bet);
                player.incrementWins();
                cout << "Congratulations! You won. +"<<bet<<"$!\nYour new balance is: $" << player.getBalance() << endl;
            } else {
                player.decreaseBalance(bet);
                player.incrementLosses();
                cout << "Sorry, you lost. Your new balance is: $" << player.getBalance() << endl;
            }
        } else {
            cout << "Invalid choice. Please enter 'heads' or 'tails'." << endl;
        }

        if (player.getBalance() == 0) {
            cout << "Game over! You've run out of balance." << endl;
            break;
        }
    }

    cout << "Thank you for playing!" << endl;
    cout << "Total Wins: " << player.getWins() << endl;
    cout << "Total Losses: " << player.getLosses() << endl;

    return 0;
}
