#include "Player.h"
#include <string>

/**
 * @brief Player class to store player data of balance, wins and losses.
*/
Player::Player()
    : balance(1000), wins(0), losses(0) {}

Player::Player(std::string initialName, int initialBalance, int initialWins, int initialLosses)
    : name(initialName), balance(initialBalance), wins(initialWins), losses(initialLosses) {}

int Player::getBalance() const
{
    return balance;
}

int Player::getWins() const
{
    return wins;
}

int Player::getLosses() const
{
    return losses;
}

const std::string& Player::getName() const
{
    return name;
}

void Player::setName(const std::string& newName)
{
    name = newName;
}

void Player::setBalance(int newBalance)
{
    balance = newBalance;
}

void Player::setWins(int newWins)
{
    wins = newWins;
}

void Player::setLosses(int newLosses)
{
    losses = newLosses;
}

void Player::increaseBalance(int amount)
{
    balance += amount;
}

void Player::decreaseBalance(int amount)
{
    balance -= amount;
}

void Player::incrementWins()
{
    wins++;
}

void Player::incrementLosses()
{
    losses++;
}
