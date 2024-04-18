#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int balance;
    int wins;
    int losses;

public:
    Player();
    Player(int initialBalance, int initialWins, int initialLosses);

    int getBalance() const;
    int getWins() const;
    int getLosses() const;

    void increaseBalance(int amount);
    void decreaseBalance(int amount);
    void incrementWins();
    void incrementLosses();
};

#endif
