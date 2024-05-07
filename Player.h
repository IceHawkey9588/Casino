#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player();
    Player(std::string initialName, int initialBalance, int initialWins, int initialLosses);

    int getBalance() const;
    int getWins() const;
    int getLosses() const;
    const std::string& getName() const;

    void setName(const std::string& newName);
    void setBalance(int newBalance);
    void setWins(int newWins);
    void setLosses(int newLosses);

    void increaseBalance(int amount);
    void decreaseBalance(int amount);
    void incrementWins();
    void incrementLosses();

private:
    std::string name;
    int balance;
    int wins;
    int losses;
};

#endif
